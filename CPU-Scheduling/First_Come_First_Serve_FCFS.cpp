#include<stdio.h>

// FCFS CPU Scheduling


int main() {

    int n;
    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    int arr[n][2];

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time of Process %d: ", i + 1);
        scanf("%d", &arr[i][0]);

        printf("Enter Burst Time of Process %d: ", i + 1);
        scanf("%d", &arr[i][1]);
    }

    // Sorting according to Arrival Time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            if (arr[i][0] > arr[j][0]) {

                int temp1 = arr[i][0];
                arr[i][0] = arr[j][0];
                arr[j][0] = temp1;

                int temp2 = arr[i][1];
                arr[i][1] = arr[j][1];
                arr[j][1] = temp2;
            }
        }
    }

    int prev = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {

        int at = arr[i][0];
        int bt = arr[i][1];

        int ct;

        if (at > prev)
            ct = at + bt;
        else
            ct = prev + bt;

        int tat = ct - at;
        int wt = tat - bt;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at, bt, ct, tat, wt);

        prev = ct;
    }

    return 0;
}
