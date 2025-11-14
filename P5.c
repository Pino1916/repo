#include<stdio.h>

int main()
{
    int bt[20], rem_bt[20], wt[20], tat[20], ct[20], p[20];
    int i, n, tq, time = 0, done;
    float total_wt = 0, total_tat = 0, avg_wt, avg_tat;

    printf("Enter number of processes: ");
    if(scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    printf("\nEnter Burst Time for each process:\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];   // remaining burst time
        p[i] = i + 1;
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    // Round Robin Execution
    while(1)
    {
        done = 1;
        for(i = 0; i < n; i++)
        {
            if(rem_bt[i] > 0)
            {
                done = 0; // still some process left

                if(rem_bt[i] > tq)
                {
                    time += tq;
                    rem_bt[i] -= tq;
                }
                else
                {
                    time += rem_bt[i];
                    rem_bt[i] = 0;
                    ct[i] = time;  // completion time
                }
            }
        }

        if(done == 1)
            break;
    }

    // Calculate TAT and WT
    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i];        // AT = 0
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }

    avg_tat = total_tat / n;
    avg_wt = total_wt / n;

    printf("\n--- Round Robin Scheduling Results ---\n");
    printf("\nProcess\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);
    
    /*#include <stdio.h>
int main()
{
    int i, j, n;
    int bu[10], wa[10], tat[10], ct[10];
    int t, max;
    float awt = 0, att = 0, temp = 0;

    printf("Enter the no of processes -- ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter Burst Time for process %d -- ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i];//copy of original BT
    }

    printf("\nEnter the size of time slice -- ");
    scanf("%d", &t);

    max = bu[0];
    for (i = 1; i < n; i++) {
        if (max < bu[i])
            max = bu[i];
    }

    for (j = 0; j < (max / t) + 1; j++) {
        for (i = 0; i < n; i++) {
            if (bu[i] != 0) {
                if (bu[i] <= t) {
                    tat[i] = temp + bu[i];
                    temp = temp + bu[i];
                    bu[i] = 0;
                } else {
                    bu[i] = bu[i] - t;
                    temp = temp + t;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }

    printf("\nThe Average Turnaround time is -- %f", att / n);
    printf("\nThe Average Waiting time is -- %f", awt / n);
    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");

    for (i = 0; i < n; i++) {
        printf("\t%d \t %d \t\t %d \t\t %d \n", i + 1, ct[i], wa[i], tat[i]);
    }

    return 0;
}
*/

    return 0;
}

