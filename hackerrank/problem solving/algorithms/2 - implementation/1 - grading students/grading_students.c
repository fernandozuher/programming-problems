// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int numbers[], int n);
void grade_students(const int grades[], int n, int rounded_grades[]);
void print_numbers(const int numbers[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    int grades[n];
    read_numbers(grades, n);

    int rounded_grades[n];
    grade_students(grades, n, rounded_grades);
    print_numbers(rounded_grades, n);

    return 0;
}

void read_numbers(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
}

void grade_students(const int grades[], int n, int rounded_grades[])
{
    for (int i = 0, min_grade = 38; i < n; ++i)
        if (grades[i] < min_grade)
            rounded_grades[i] = grades[i];
        else {
            int next_multiple_5 = (grades[i] / 5 + 1) * 5;
            rounded_grades[i] = next_multiple_5 - grades[i] < 3 ? next_multiple_5 : grades[i];
        }
}

void print_numbers(const int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d\n", numbers[i]);
}
