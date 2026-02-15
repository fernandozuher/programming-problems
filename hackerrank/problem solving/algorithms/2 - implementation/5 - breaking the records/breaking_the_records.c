// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

#include <stdio.h>

typedef struct {
    int most_record_breaks;
    int least_record_breaks;
} records_t;

void read_numbers(int *arr, int n);
records_t breaking_records(const int *scores, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int scores[n];
    read_numbers(scores, n);

    records_t records = breaking_records(scores, n);
    printf("%d %d\n", records.most_record_breaks, records.least_record_breaks);

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of array scores
// T: O(n)
// S: O(1) extra space
records_t breaking_records(const int *scores, int n)
{
    int most_record_breaks = 0, least_record_breaks = 0;

    for (int i = 0, most_points = scores[0], least_points = scores[0]; i < n; ++i)
        if (scores[i] > most_points) {
            most_points = scores[i];
            ++most_record_breaks;
        } else if (scores[i] < least_points) {
            least_points = scores[i];
            ++least_record_breaks;
        }

    return (records_t){most_record_breaks, least_record_breaks};
}
