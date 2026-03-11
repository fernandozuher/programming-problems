// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int *arr, int n);
bool angry_professor(const int *arrival_times, int n, int threshold);

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int size, threshold;
        scanf("%d %d", &size, &threshold);
        int arrival_times[size];
        read_numbers(arrival_times, size);
        puts(angry_professor(arrival_times, size, threshold) ? "YES" : "NO");
    }

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// k: length of arrival_times
// T: O(k)
// S: O(1) extra space
bool angry_professor(const int *arrival_times, int n, int threshold)
{
    int on_time = 0;
    for (int i = 0; i < n; ++i)
            on_time += arrival_times[i] <= 0;
    return on_time < threshold;
}
