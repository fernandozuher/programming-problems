// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int n);
int* breaking_records(const int* const scores, const int n);

int main()
{
    int n;
    scanf("%d", &n);
    int *array = read_int_array(n);

    int *result = breaking_records(array, n);
    printf("%d %d\n", result[0], result[1]);
    
    free(array);
    free(result);
    array = result = NULL;

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int* breaking_records(const int* const scores, const int n)
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

        const int n_result = 2;
        int *records = (int*) calloc(n_result, sizeof(int));
        records[0] = breaking_most_points_records;
        records[1] = breaking_least_points_records;
        return records;
    }
