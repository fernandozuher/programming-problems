// Source: https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int read_one_int();
bool angry_professor();
    int count_early_arrival_time(const int n_students);


int main() {
    const int n_test_cases = read_one_int();
    bool results[n_test_cases];

    for (int i = 0; i < n_test_cases; results[i++] = angry_professor());
    for (int i = 0; i < n_test_cases; puts(results[i++] ? "YES" : "NO"));

    return 0;
}

    int read_one_int() {
        int number;
        char white_space_or_eof;
        scanf("%d%c", &number, &white_space_or_eof);
        return number;
    }

    bool angry_professor() {
        const int n_students_arrival_time = read_one_int();
        const int cancellation_threshold = read_one_int();
        const bool cancelled_class = count_early_arrival_time(n_students_arrival_time) < cancellation_threshold;
        return cancelled_class;
    }

        int count_early_arrival_time(const int n_students_arrival_time) {
            int early_arrival_time_count = 0;

            for (int i = 0, student_arrival_time; i < n_students_arrival_time; i++) {
                student_arrival_time = read_one_int();

                if (student_arrival_time <= 0)
                    early_arrival_time_count++;
            }

            return early_arrival_time_count;
        }
