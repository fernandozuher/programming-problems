// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int *arr, int n);
int min_distance(const int *arr, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    read_numbers(arr, n);
    printf("%d\n", min_distance(arr, n));
    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

int min_distance(const int *arr, int n)
{
    constexpr int limit = 100000;
    int last_seen[limit];
    for (int i = 0; i < limit; ++i)
        last_seen[i] = -1;

    int min_dist = -1;

    for (int i = 0; i < n; ++i) {
        int x = arr[i];

        if (last_seen[x] != -1) {
            int dist = i - last_seen[x];
            if (min_dist == -1 || dist < min_dist) {
                min_dist = dist;
                if (min_dist == 1) {
                    return 1;
                }
            }
        }
        last_seen[x] = i;
    }

    return min_dist;
}
