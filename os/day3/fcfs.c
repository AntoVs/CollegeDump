#include <stdio.h>

int main() {
    int n, i, j, temp;
    int at[10], bt[10], ct[10], tat[10], wt[10], pid[10];
    int time = 0;
    int totalTAT = 0, totalWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++) {
        if(time < at[i])
            time = at[i];

        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        time = ct[i];
        totalTAT += tat[i];
        totalWT += wt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAvg TAT = %.2f", (float)totalTAT / n);
    printf("\nAvg WT  = %.2f", (float)totalWT / n);
    printf("\nThroughput = %.2f\n", (float)n / time);

    printf("\nGantt Chart:\n|");
    for(i = 0; i < n; i++)
        printf(" P%d |", pid[i]);

    printf("\n");
    printf("%d", at[0]);
    for(i = 0; i < n; i++)
        printf("   %d", ct[i]);
    printf("\n");
    return 0;
}