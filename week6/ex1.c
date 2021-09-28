#include <stdio.h>
#include <stdlib.h>

struct process{
	int arrival;
	int burst;
	int compl;
	int tat;
	int wait;
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
	int n;
	double tat_avg, wait_avg;
	printf("Please enter number of processes: ");
	scanf("%d", &n);
	struct process* pr = malloc(n * sizeof(struct process));
	for (int i = 0; i < n; i++){
		printf("Please enter arrival time of process[%i]\n", i + 1);
		scanf("%d", &pr[i].arrival);
		printf("Please enter burst time of process[%i]\n", i + 1);
		scanf("%d", &pr[i].burst);
		pr[i].id = i + 1;
	}
	qsort(pr, n, sizeof(struct process), comp);
	
	pr[0].tat = pr[0].burst;
	pr[0].wait = 0;
	pr[0].compl = pr[0].burst + pr[0].arrival;
	
	tat_avg += pr[0].tat;
	wait_avg += pr[0].wait;
	
	for(int i = 1; i < n; i++){
		pr[i].wait = (pr[i - 1].compl + pr[i].burst) - (pr[i].arrival + pr[i].burst);
		pr[i].tat = pr[i].burst + pr[i].wait;
		pr[i].compl = pr[i].arrival + pr[i].tat;
		
		tat_avg += pr[i].tat;
		wait_avg += pr[i].wait;
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

