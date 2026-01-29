#include <stdio.h>
int main(){
    int n, tq, i, time = 0, completed = 0;
    int bt[10], rem[10], ct[10], tat[10], wt[10];
    int totalTAT = 0, totalWT = 0;

    int ganttP[100], ganttT[100], g = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter BT for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while(completed < n) {
        for(i = 0; i < n; i++) {
            if(rem[i] > 0) {
                ganttP[g] = i + 1;
                ganttT[g] = time;

                if(rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    rem[i] = 0;
                    ct[i] = time;
                    completed++;
                }
                g++;
            }
        }
    }

    printf("\nP\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
        totalTAT += tat[i];
        totalWT += wt[i];
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i + 1, bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAvg TAT = %.2f", (float)totalTAT / n);
    printf("\nAvg WT  = %.2f", (float)totalWT / n);
    printf("\nThroughput = %.2f", (float)n / time);
    printf("\nContext Switch Count = %d\n", g - 1);

    printf("\nGantt Chart:\n|");
    for(i = 0; i < g; i++)
        printf(" P%d |", ganttP[i]);

    printf("\n0");
    for(i = 0; i < g; i++)
        printf("   %d", (i + 1 < g) ? ganttT[i + 1] : time);

    printf("\n");
    return 0;
}