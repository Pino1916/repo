#include<stdio.h>

int main()
{
    int bt[20], p[20], wt[20], tat[20], ct[20];
    int i, j, n, temp;
    float total_wt = 0, total_tat = 0, avg_wt, avg_tat;

    printf("Enter number of processes: ");
    if(scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    // Considering all arrival times = 0
    printf("\nEnter Burst Time:\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    // Sort according to Burst Time (SJF)
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Compute Completion Time (CT)
    ct[0] = bt[0];
    for(i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
    }

    // Compute Turnaround Time (TAT) and Waiting Time (WT)
    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i];        // since AT = 0
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];
    }

    avg_tat = total_tat / n;
    avg_wt = total_wt / n;

    printf("\n--- SJF (Non-Preemptive) Scheduling Results ---\n");
    printf("\nProcess\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);

    return 0;
}

