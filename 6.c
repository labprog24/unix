#include <stdio.h>

int main() {
    int limit, total = 0, counter = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0;
    float average_wait_time, average_turnaround_time;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &limit);
    
    int arrival_time[limit], burst_time[limit], temp[limit];
    
    for (int i = 0; i < limit; i++) {
        printf("\nEnter Arrival Time and Burst Time for Process[%d]: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        temp[i] = burst_time[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &time_quantum);
    
    printf("\nProcess ID\tBurst Time\tTurnaround Time\tWaiting Time\n");
    
    for (int x = limit; x != 0;) {
        for (int i = 0; i < limit; i++) {
            if (temp[i] <= time_quantum && temp[i] > 0) {
                total += temp[i];
                temp[i] = 0;
                counter = 1;
            } else if (temp[i] > 0) {
                temp[i] -= time_quantum;
                total += time_quantum;
            }

            if (temp[i] == 0 && counter == 1) {
                x--;
                printf("Process[%d]\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                wait_time += total - arrival_time[i] - burst_time[i];
                turnaround_time += total - arrival_time[i];
                counter = 0;
            }
        }
    }

    average_wait_time = (float)wait_time / limit;
    average_turnaround_time = (float)turnaround_time / limit;

    printf("\nAverage Waiting Time: %f\n", average_wait_time);
    printf("Average Turnaround Time: %f\n", average_turnaround_time);

    return 0;
}

