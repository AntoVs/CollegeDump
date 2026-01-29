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
/* Access existing shared memory */
    shmid = shmget(key, sizeof(struct shared_buffer), 0666);
    shm = (struct shared_buffer*) shmat(shmid, NULL, 0);
/* Access existing semaphores */
    semid = semget(key, 3, 0666);

    int item;
    for (int i = 0; i < 10; i++) {
        wait(semid, 2); // full
        wait(semid, 0); // mutex
        item = shm->buffer[shm->out];
        printf("Consumer consumed: %d\n", item);
        shm->out = (shm->out + 1) % BUFFER_SIZE;
        signal(semid, 0); // mutex
        signal(semid, 1); // empty
        sleep(1);
    }
    shmdt(shm);
    return 0;
}