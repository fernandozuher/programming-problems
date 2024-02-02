// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* read_int_array(const int n);
bool angry_professor(const int* const students_arrival_time, const int n, const int cancellation_threshold);
    int count_early_arrival_time(const int* const students_arrival_time, int n);

int main()
{
    int n;
    scanf("%d", &n);
    bool cancelled_classes[n];

    for (int i = 0; i < n; ++i) {
        int n_students_arrival_time, cancellation_threshold;
        scanf("%d %d", &n_students_arrival_time, &cancellation_threshold);
        int *students_arrival_time = read_int_array(n_students_arrival_time);
        cancelled_classes[i] = angry_professor(students_arrival_time, n_students_arrival_time, cancellation_threshold);

        free(students_arrival_time);
        students_arrival_time = NULL;
    }

    for (int i = 0; i < n; puts(cancelled_classes[i++] ? "YES" : "NO"));

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    bool angry_professor(const int* const students_arrival_time, const int n, const int cancellation_threshold)
    {
        bool cancelled_class = count_early_arrival_time(students_arrival_time, n) < cancellation_threshold;
        return cancelled_class;
    }

        int count_early_arrival_time(const int* const students_arrival_time, int n)
        {
            int early_arrival_time_count = 0;

            while (n--)
                if (students_arrival_time[n] <= 0)
                    ++early_arrival_time_count;

            return early_arrival_time_count;
        }
