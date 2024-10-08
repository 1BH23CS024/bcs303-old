#include <stdio.h>

void main()
{
    int x, n, p[10], priority[10], pt[10], wt[10], tat[10], avg_wt, avg_tat, i;

    printf("Number of Process = ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d", i + 1);
        printf("\nTime = ");
        scanf("%d", &pt[i]);
        printf("Priority = ");
        scanf("%d", &priority[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (priority[i] < priority[j])
            {
                x = priority[i];
                priority[i] = priority[j];
                priority[j] = x;
                x = pt[i];
                pt[i] = pt[j];
                pt[j] = x;
                x = p[i];
                p[i] = p[j];
                p[j] = x;
            }
        }
    }

    wt[0] = 0;
    avg_wt = 0;
    tat[0] = pt[0];
    avg_tat = tat[0];

    for (i = 1; i < n; i++)
    {
        wt[i] = tat[i - 1];
        avg_wt += wt[i];
        tat[i] = wt[i] + pt[i];
        avg_tat += tat[i];
    }

    printf("\nJob\tPriority\tBurst Time\tWait Time\tTurn Around Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], priority[i], pt[i], wt[i], tat[i]);
    }

    printf("\nAverage Wait Time = %d", avg_wt /= n);
    printf("\nAverage Turn Around Time = %d\n", avg_tat /= n);
}