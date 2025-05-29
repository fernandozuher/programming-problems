// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int numbers[], int n);
void grade_students(const int grades[], int n, int rounded_grades[]);
bool is_zero_remainder(int grade);
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
        if (grades[i] < min_grade || is_zero_remainder(grades[i]))
            rounded_grades[i] = grades[i];
        else {
            int quotient = grades[i] / 5;
            int next_multiple_5 = (quotient + 1) * 5;
            int difference = next_multiple_5 - grades[i];
            rounded_grades[i] = difference < 3 ? next_multiple_5 : grades[i];
        }
}

bool is_zero_remainder(int grade)
{
    return grade % 5 == 0;
}

void print_numbers(const int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d\n", numbers[i]);
}
