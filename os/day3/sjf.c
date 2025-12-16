#include <stdio.h>
int main(){
	int n, i, completed = 0, time = 0;
	int at[10], bt[10], ct[10], tat[10], wt[10], done[10] = {0};
	int tota = 0,totwt = 0;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("Enter AT and BT for P%d: ", i+1);
		scanf("%d %d", &at[i], &bt[i]);
	}
	while(completed < n){
		int min = 9999, idx = -1;
		for(i = 0; i < n; i++) {
			if(at[i] <= time && !done[i] && bt[i] < min) {
				min = bt[i];
				idx = i;
			}
		}
		if(idx == -1) time++;
		else{
			time += bt[idx];
			ct[idx] = time;
			tat[idx] = ct[idx] - at[idx];
			wt[idx] = tat[idx] - bt[idx];
			done[idx] = 1;
			tota = tota + tat[idx];
			totwt = totwt + wt[idx];
			completed++;
		}
	}
	printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
	for(i = 0; i < n; i++)
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
	printf("Avg Tat = %.2f\n",(float)(tota/n));
	printf("Avg wt = %.2f\n",(float)(totwt/n));
	printf("Throughput = %.2f\n",(float)n/time);
	return 0;
}
