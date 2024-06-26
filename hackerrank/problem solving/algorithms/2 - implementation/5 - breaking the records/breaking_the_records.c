// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true
// From C23

#include <stdio.h>
#include <stdlib.h>

int *read_int_array(int n);
int *breaking_records(const int scores[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    int *array = read_int_array(n);

    int *records = breaking_records(array, n);
    printf("%d %d\n", records[0], records[1]);

    free(array);
    free(records);

    return 0;
}

    int *read_int_array(const int n)
    {
        auto array = (int*) malloc(n * sizeof(int));
        for (int i = 0; i < n; ++i)
            scanf("%d", &array[i]);
        return array;
    }

    int *breaking_records(const int scores[], const int n)
    {
        int most_points = scores[0], breaking_most_points_records = 0;
        int least_points = scores[0], breaking_least_points_records = 0;

        for (int i = 1; i < n; ++i)
            if (scores[i] > most_points) {
                most_points = scores[i];
                ++breaking_most_points_records;
            }
            else if (scores[i] < least_points) {
                least_points = scores[i];
                ++breaking_least_points_records;
            }

        constexpr int n_records = 2;
        auto records = (int*) malloc(n_records * sizeof(int));
        records[0] = breaking_most_points_records;
        records[1] = breaking_least_points_records;
        return records;
    }
