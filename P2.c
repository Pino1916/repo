#include<stdio.h>

int main()
{
    int bt[20], at[20], p[20], wt[20], tat[20], ct[20];
    int i, j, n, temp;
    float total_wt = 0, total_tat = 0, avg_wt, avg_tat;

    printf("Enter number of processes: ");
    if(scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    printf("\nEnter Arrival Time and Burst Time:\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(at[i] > at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    ct[0] = at[0] + bt[0];
    
    for(i = 1; i < n; i++)
    {
        if(at[i] > ct[i-1])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        
        total_tat += tat[i];
        total_wt += wt[i];
    }

    avg_tat = total_tat / n;
    avg_wt = total_wt / n;

    printf("\n--- FCFS Scheduling Results ---\n");
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);

    return 0;
}
