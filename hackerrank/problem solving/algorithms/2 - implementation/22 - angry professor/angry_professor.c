// Source: https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int read_one_int();
char* angry_professor();
int count_late_arrival_time(const int n_students, const int cancellation_threshold);


int main() {
    int nTestCases = read_one_int();

    char *nResults[nTestCases];

    for (int i = 0; i < nTestCases; ++i)
        nResults[i] = angry_professor();

    for (int i = 0; i < nTestCases; ++i)
        puts(nResults[i]);

    return 0;
}

int read_one_int() {
    int n;
    char white_space_or_eof;
    scanf("%d%c", &n, &white_space_or_eof);
    return n;
}

char* angry_professor() {
    const int n_students = read_one_int();
    const int cancellation_threshold = read_one_int();

    const int late_arrival_time_count = count_late_arrival_time(n_students, cancellation_threshold);

    char *is_class_happening = late_arrival_time_count < cancellation_threshold ? "YES" : "NO";
    return is_class_happening;
}

int count_late_arrival_time(const int n_students, const int cancellation_threshold) {
    int late_arrival_time_count = 0;

    for (int i = 0; i < n_students; i++) {
        const int student_arrival_time = read_one_int();

        if (student_arrival_time > 0)
            late_arrival_time_count++;
    }

    return late_arrival_time_count;
}
