#include <stdio.h>
int main(){
	int n, i, completed = 0, time = 0;
	int at[10], bt[10], pr[10], ct[10],tat[10],wt[10],done[10]={0};
	int tota = 0,totwt = 0;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("Enter AT, BT, Priority for P%d: ", i+1);
		scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
	}
	while(completed < n) {
		int best = 9999, idx = -1;
		for(i = 0; i < n; i++) {
			if(at[i] <= time && !done[i] && pr[i] < best) {
				best = pr[i];
				idx = i;
			}
		}
		if(idx == -1) time++;
		else{
			time += bt[idx];
			ct[idx] = time;
			tat[idx] = ct[idx] - at[idx];	
			wt[idx] = tat[idx] - bt[idx];
			tota = tota + tat[idx];
			totwt = totwt + wt[idx];
			done[idx] = 1;
			completed++;
		}
	}
	printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
	for(i = 0; i < n; i++)
		printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
	printf("Avg Tat = %.2f\n",(float)(tota/n));
	printf("Avg wt = %.2f\n",(float)(totwt/n));
	printf("Throughput = %.2f\n",(float)n/time);
	return 0;
}
