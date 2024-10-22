#include <stdio.h>

struct process_control_block
{
    int p_num, arrival_time, burst_time;
    int completion_time, start_time, turn_around_time, waiting_time;
} p[10] = {0};

void main()
{
    int i, j, n;
    int start_time[10], completion_time[10];
    float total_wt = 0, total_tat = 0;

    printf("Number of Process = ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nProcess Number = ");
        scanf("%d", &p[i].p_num);

        printf("\tArrival Time = ");
        scanf("%d", &p[i].arrival_time);

        printf("\tBurst Time = ");
        scanf("%d", &p[i].burst_time);
    }

    printf("\nProcess Name\tArrival Time\tBurst Time\tStart Time\tCompletion Time\t\tWaiting Time\tTurn Around Time\n");
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            p[i].start_time = p[i].arrival_time;
        else
            p[i].start_time = p[i - 1].completion_time;

        p[i].waiting_time = p[i].start_time - p[i].arrival_time;
        p[i].completion_time = p[i].start_time + p[i].burst_time;
        p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n", p[i].p_num, p[i].arrival_time, p[i].burst_time, p[i].start_time, p[i].completion_time, p[i].waiting_time, p[i].turn_around_time);
        total_wt += p[i].waiting_time;
        total_tat += p[i].turn_around_time;
    }

    printf("\nAverage Waiting Time = %f\n", total_wt / n);
    printf("Average Turn Around Time = %f\n", total_tat / n);
}