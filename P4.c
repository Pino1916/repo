#include<stdio.h>

int main()
{
    int bt[20], p[20], pr[20], wt[20], tat[20], ct[20];
    int i, j, n, temp;
    float total_wt = 0, total_tat = 0, avg_wt, avg_tat;

    printf("Enter number of processes: ");
    if(scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    // Considering all arrival times = 0
    printf("\nEnter Burst Time and Priority (Lower number = Higher priority):\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        p[i] = i + 1;
    }

    // Sort according to Priority (Lower number = higher priority)
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(pr[i] > pr[j])
            {
                // swap priority
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // swap process ID
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

    printf("\n--- Priority Scheduling (Non-Preemptive) Results ---\n");
    printf("\nProcess\tPr\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], pr[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);

    return 0;
}

