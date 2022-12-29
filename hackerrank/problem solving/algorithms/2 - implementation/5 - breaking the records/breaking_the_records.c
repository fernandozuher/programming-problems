// Source: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_line_as_int_array(int n);
int* breaking_records(int* scores, int scores_size);

int main() {
    int *arraySize = read_line_as_int_array(1);
    int n1 = arraySize[0];
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
        int least_points = scores[0], least_points_count = 0;
        int most_points = scores[0], most_points_count = 0;

        for (int i = 1; i < scores_size; i++) {
            if (scores[i] > most_points) {
                most_points = scores[i];
                most_points_count++;
            }
            else if (scores[i] < least_points) {
                least_points = scores[i];
                least_points_count++;
            }
        }

        int *records = (int*) calloc(2, sizeof(int));
        records[0] = most_points_count;
        records[1] = least_points_count;
        return records;
    }