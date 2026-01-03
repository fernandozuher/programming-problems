// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int arr[], int n);
int *grading_students(int *grades, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int grades[n];
    read_numbers(grades, n);

    grading_students(grades, n);
    for (int i = 0; i < n; ++i)
        printf("%d\n", grades[i]);

    return 0;
}

void read_numbers(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of array grades
// T: O(n)
// S: O(1) extra space
int *grading_students(int *grades, int n)
{
    for (int i = 0, min_grade = 38; i < n; ++i)
        if (grades[i] >= min_grade) {
            int next_multiple_5 = (grades[i] / 5 + 1) * 5;
            if (next_multiple_5 - grades[i] < 3)
                grades[i] = next_multiple_5;
        }
    return grades;
}
