#include <stdio.h>
int main() {
	int n, tq, i, time = 0, completed = 0;
	int bt[10], rem[10], ct[10], tat[10], wt[10];
	int tota = 0,totwt = 0;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("Enter BT for P%d: ", i+1);
		scanf("%d", &bt[i]);
		rem[i] = bt[i];
	}
	printf("Enter Time Quantum: ");
	scanf("%d", &tq);
	while(completed < n) {
		for(i = 0; i < n; i++) {
			if(rem[i] > 0) {
				if(rem[i] > tq) {
					time += tq;
					rem[i] -= tq;
				}else{
					time += rem[i];
					ct[i] = time;
					rem[i] = 0;
					completed++;
				}
			}
		}
	}
	printf("\nP\tBT\tCT\tTAT\tWT\n");
	for(i = 0; i < n; i++){
		tat[i] = ct[i];
		wt[i] = tat[i] - bt[i];
		printf("P%d\t%d\t%d\t%d\t%d\n",i+1, bt[i], ct[i], tat[i], wt[i]);
		tota = tota + tat[i];
		totwt = totwt + wt[i];
	}
	printf("Avg Tat = %f\n",(float)(tota/n));
	printf("Avg wt = %f\n",(float)(totwt/n));
	printf("Throughput = %f\n",(float)n/time);
	return 0;
}
