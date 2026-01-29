#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#define BUFFER_SIZE 5

struct shared_buffer {
    int buffer[BUFFER_SIZE];
    int in;
    int out;
};

/* Semaphore wait */
void wait(int semid, int semnum) {
    struct sembuf op;
    op.sem_num = semnum;
    op.sem_op = -1;
    op.sem_flg = 0;
    semop(semid, &op, 1);
}

/* Semaphore signal */
void signal(int semid, int semnum) {
    struct sembuf op;
    op.sem_num = semnum;
    op.sem_op = 1;
    op.sem_flg = 0;
    semop(semid, &op, 1);
}

int main() {
    int shmid, semid;
    struct shared_buffer *shm;
    key_t key = ftok("shmfile", 65);

/* Create shared memory */
    shmid = shmget(key, sizeof(struct shared_buffer), 0666 | IPC_CREAT);
    shm = (struct shared_buffer*) shmat(shmid, NULL, 0);
/* Create semaphore set (3 semaphores) */
    semid = semget(key, 3, 0666 | IPC_CREAT);
/* Initialize semaphores */
    semctl(semid, 0, SETVAL, 1); // mutex
    semctl(semid, 1, SETVAL, BUFFER_SIZE); // empty
    semctl(semid, 2, SETVAL, 0); // full
    shm->in = 0;
    shm->out = 0;
    int item;
    for (int i = 0; i < 10; i++) {
        item = rand() % 100;
        wait(semid, 1); // empty
        wait(semid, 0); // mutex
        shm->buffer[shm->in] = item;
        printf("Producer produced: %d\n", item);
        shm->in = (shm->in + 1) % BUFFER_SIZE;
        signal(semid, 0); // mutex
        signal(semid, 2); // full
        sleep(1);
    }
    shmdt(shm);
    return 0;
}