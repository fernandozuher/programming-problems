// Source: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_line_as_int_array(int n);
int* breaking_records(int* scores, int scores_size);

int main() {
    int *array_size = read_line_as_int_array(1);
    int n1 = array_size[0];
    int *set_a = read_line_as_int_array(n1);

    int *result = breaking_records(set_a, n1);
    printf("%d %d\n", result[0], result[1]);

    return 0;
}

    int* read_line_as_int_array(int n) {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &array[i]);
        return array;
    }

    int* breaking_records(int* scores, int scores_size) {
        int most_points = scores[0], _breaking_most_points_records = 0;
        int least_points = scores[0], _breaking_least_points_records = 0;

        for (int i = 1; i < scores_size; i++)
            if (scores[i] > most_points) {
                most_points = scores[i];
                _breaking_most_points_records++;
            }
            else if (scores[i] < least_points) {
                least_points = scores[i];
                _breaking_least_points_records++;
            }

        int *records = (int*) calloc(2, sizeof(int));
        records[0] = _breaking_most_points_records;
        records[1] = _breaking_least_points_records;
        return records;
    }
