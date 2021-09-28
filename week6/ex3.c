#include <stdio.h>
#include <stdlib.h>

struct process{
	int arrival;
	int burst;
	int burst_new;
	int compl;
	int tat;
	int wait;
	int left;
	int id;
};

int comp(const void *v1, const void *v2){
	struct process l = *(struct process*) v1;
	struct process r = *(struct process*) v2;
	return l.arrival - r.arrival;
}
int id(const void *v1, const void *v2){
	struct process l = *(struct process*) v1;
	struct process r = *(struct process*) v2;
	return l.id - r.id;
}

int main(){
	int n, q, count = 0, proc = 0;
	double tat_avg, wait_avg;
	printf("Please enter number of processes: ");
	scanf("%d", &n);
	printf("Please enter quantum: ");
	scanf("%d", &q);
	struct process* pr = malloc(n * sizeof(struct process));
	for (int i = 0; i < n; i++){
		printf("Please enter arrival time of process[%i]\n", i + 1);
		scanf("%d", &pr[i].arrival);
		printf("Please enter burst time of process[%i]\n", i + 1);
		scanf("%d", &pr[i].burst);
		pr[i].burst_new = pr[i].burst;
		pr[i].id = i + 1;
	}
	qsort(pr, n, sizeof(struct process), comp);
	
	while(proc < n){
	
		proc = 0;
		for(int i = 0; i < n; i++) {
			if(pr[i].burst_new <= q) {
				proc++;
			}
		}
		
		if(pr[0].burst <= q) {
			pr[0].tat = pr[0].burst;
			pr[0].wait = 0;
			pr[0].compl = pr[0].burst + pr[0].arrival;
			
			tat_avg += pr[0].tat;
			wait_avg += pr[0].wait;
		}
		else{
			pr[0].tat = q;
			pr[0].wait = 0;
			pr[0].compl = q + pr[0].arrival;
			pr[0].left = pr[0].burst - q;
			count++;
		}
	
		for(int i = 1; i < n; i++){
			if(pr[i].burst <= q) {
				pr[i].wait = (pr[i - 1].compl + pr[i].burst) - (pr[i].arrival + pr[i].burst);
				pr[i].tat = pr[i].burst + pr[i].wait;
				pr[i].compl = pr[i].arrival + pr[i].tat;
				
				tat_avg += pr[i].tat;
				wait_avg += pr[i].wait;
			}
			else {
				pr[i].wait = (pr[i - 1].compl + q) - (pr[i].arrival + q);
				pr[i].tat = q + pr[i].wait;
				pr[i].compl = pr[i].arrival + pr[i].tat;
				pr[i].left = pr[i].burst - q;
				count++;
			}
		}
		
		if(pr[0].burst > q){
			pr[0].wait = pr[n - 1].compl + pr[0].left - q;
			pr[0].tat = pr[0].burst + pr[0].wait;
			pr[0].compl = pr[0].arrival + pr[0].tat;
			pr[0].burst_new -= q;
		}
		
		for(int i = 1; i < n; i++) {
			if(pr[i].burst > q) {
				pr[i].wait = count * 3 + pr[i].wait;
				pr[i].tat = pr[i].burst + pr[i].wait;
				pr[i].compl = pr[i].arrival + pr[i].tat;
				pr[i].burst_new -= q;
				count--;
			}
		}
	}
	
	tat_avg /= n;
	wait_avg /= n;
	qsort(pr, n, sizeof(struct process), id);
	printf("\nP#\tAT\tBT\tCT\tTAT\tWT\n");
	for (int i = 0; i < n; i++)
	{
		printf("P%i\t%i\t%i\t%i\t%i\t%i\n", i + 1, pr[i].arrival, pr[i].burst, pr[i].compl, pr[i].tat, pr[i].wait);
	}
	printf("Average TAT: %f\n", tat_avg);
	printf("Average WT: %f\n", wait_avg);
	
}

