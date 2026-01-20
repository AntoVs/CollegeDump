#include <stdio.h>

int main(){
    int n, i, completed = 0, time = 0;
    int at[10], bt[10], ct[10], tat[10], wt[10], done[10] = {0};
    int totalTAT = 0, totalWT = 0;

    int ganttP[10], ganttT[10], g = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    while(completed < n) {
        int min = 9999, idx = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && !done[i] && bt[i] < min) {
                min = bt[i];
                idx = i;
            }
        }

        if(idx == -1) {
            time++;
        } else {
            ganttP[g] = idx + 1;
            ganttT[g] = time;

            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            totalTAT += tat[idx];
            totalWT += wt[idx];

            done[idx] = 1;
            completed++;
            g++;
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    printf("\nAvg TAT = %.2f", (float)totalTAT / n);
    printf("\nAvg WT  = %.2f", (float)totalWT / n);
    printf("\nThroughput = %.2f\n", (float)n / time);

    printf("\nGantt Chart:\n|");
    for(i = 0; i < g; i++)
        printf(" P%d |", ganttP[i]);

    printf("\n0");
    for(i = 0; i < g; i++)
        printf("   %d", (i + 1 < g) ? ganttT[i + 1] : time);

    printf("\n");

    return 0;
}