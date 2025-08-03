// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int numbers[], int n);
bool angry_professor(const int arrival_times[], int n, int threshold);

int main()
{
    int n;
    scanf("%d", &n);
    bool cancelled_classes[n];

    for (int i = 0; i < n; ++i) {
        int n, threshold;
        scanf("%d %d", &n, &threshold);
        int arrival_times[n];
        read_numbers(arrival_times, n);
        cancelled_classes[i] = angry_professor(arrival_times, n, threshold);
    }

    for (int i = 0; i < n; ++i)
        puts(cancelled_classes[i] ? "YES" : "NO");

    return 0;
}

void read_numbers(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
}

bool angry_professor(const int arrival_times[], int n, int threshold)
{
    int count = 0;
    while (n--)
        if (arrival_times[n] <= 0)
            ++count;
    return count < threshold;
}
