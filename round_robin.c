#include <stdio.h>

struct process
{
    int burst, wait, comp, f;
} p[20] = {0, 0};

void main()
{
    int n, i, j, quantum, flag = 1, time = 0;
    float total_wt = 0, total_tat = 0;

    printf("Number of Process = ");
    scanf("%d", &n);

    printf("Enter Quantum Time = ");
    scanf("%d", &quantum);

    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Burst Time for Process %d = ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].f = 1;
    }

    printf("\nProcess Number\tStarting Time\tEnding Time\tRemaining Time");
    while (flag == 1)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (p[i].f == 1)
            {
                flag = 1;
                j = quantum;
                if ((p[i].burst - p[i].comp) > quantum)
                {
                    p[i].comp += quantum;
                }
                else
                {
                    p[i].wait = time - p[i].comp;
                    j = p[i].burst - p[i].comp;
                    p[i].comp = p[i].burst;
                    p[i].f = 0;
                }
                printf("\nProcess %d\t%d\t\t%d\t\t%d", i + 1, time, time + j, p[i].burst - p[i].comp);
                time += j;
            }
        }
    }

    printf("\n\nProcess Number\tWaiting Time\tTurn Around Time");
    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d\t%d\t\t%d", i + 1, p[i].wait, p[i].wait + p[i].burst);
        total_wt += p[i].wait;
        total_tat += p[i].wait + p[i].burst;
    }

    printf("\n\nAverage Waiting Time = %f\n", total_wt / n);
    printf("Average Turn Around Time = %f\n", total_tat / n);
}