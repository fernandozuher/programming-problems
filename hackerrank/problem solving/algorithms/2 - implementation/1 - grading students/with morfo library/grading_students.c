// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

#include <stdlib.h>
#include "morfo/io.h"

void grading_students(int *grades, int n);

int main()
{
    int n = morfo_read(int);
    int *grades = morfo_read_n_alloc(int, n);

    grading_students(grades, n);
    morfo_println(grades, n);

    free(grades);
    return 0;
}

// n: length of grades
// T: O(n)
// S: O(1) extra space
void grading_students(int *grades, int n)
{
    for (int i = 0, min_grade = 38; i < n; ++i)
        if (grades[i] >= min_grade) {
            int next_multiple_5 = (grades[i] / 5 + 1) * 5;
            if (next_multiple_5 - grades[i] < 3)
                grades[i] = next_multiple_5;
        }
}
