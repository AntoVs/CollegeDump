#include <stdio.h>
#define MAXP 10
#define MAXR 10

int n, m;
int Available[MAXR];
int Max[MAXP][MAXR];
int Allocation[MAXP][MAXR];
int Need[MAXP][MAXR];

void calculateNeed() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];
}

void displayNeed() {
    printf("\nNeed Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", Need[i][j]);
        printf("\n");
    }
     printf("\n");
}

int SafetyAlgorithm() {
    int Work[MAXR];
    int Finish[MAXP] = {0};
    int safeSeq[MAXP];
    int count = 0;

    for (int j = 0; j < m; j++)
        Work[j] = Available[j];

    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (Finish[i] == 0) {
                int flag = 1;
                for (int j = 0; j < m; j++) {
                    if (Need[i][j] > Work[j]) {
                        flag = 0;
                        break;
                    }
                }

                if (flag == 1) {
                    for (int j = 0; j < m; j++)
                        Work[j] = Work[j] + Allocation[i][j];

                    Finish[i] = 1;
                    safeSeq[count++] = i;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("System is NOT in Safe State\n");
            return 0;
        }
    }

    printf("System is in Safe State\nSafe Sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 1;
}

void resourceRequest() {
    int Request[MAXR];
    int pid;

    printf("\nEnter process number making request: ");
    scanf("%d", &pid);

    printf("Enter request vector:\n");
    for (int j = 0; j < m; j++)
        scanf("%d", &Request[j]);

    // Step 1: Request <= Need
    for (int j = 0; j < m; j++) {
        if (Request[j] > Need[pid][j]) {
            printf("Error: Process exceeded maximum claim\n");
            return;
        }
    }

    // Step 2: Request <= Available
    for (int j = 0; j < m; j++) {
        if (Request[j] > Available[j]) {
            printf("Process must wait\n");
            return;
        }
    }

    // Step 3: Pretend allocation
    for (int j = 0; j < m; j++) {
        Available[j] -= Request[j];
        Allocation[pid][j] += Request[j];
        Need[pid][j] -= Request[j];
    }

    // Step 4: Safety check
    if (SafetyAlgorithm()) {
        printf("Request granted\n");
    } else {
        for (int j = 0; j < m; j++) {
            Available[j] += Request[j];
            Allocation[pid][j] -= Request[j];
            Need[pid][j] += Request[j];
        }
        printf("Request denied\n");
    }
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);
    printf("\nEnter Max matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &Max[i][j]);

    printf("\nEnter Allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &Allocation[i][j]);

    printf("\nEnter Available resources:\n");
    for (int j = 0; j < m; j++)
        scanf("%d", &Available[j]);

    calculateNeed();    // Compute Need matrix
    displayNeed();      // Display Need matrix

    SafetyAlgorithm();  // Check system safe state

    resourceRequest();  // Optional: check resource request

    return 0;
}
