// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int n);
int* grading_students(const int *grades, const int n);
bool is_zero_remainder(const int grade);
void print_array(const int *array, const int n);

int main()
{
    int n;
    scanf("%d", &n);

    int *array = read_int_array(n);
    int *result = grading_students(array, n);
    print_array(result, n);

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int* grading_students(const int *grades, const int n)
    {
        int *new_grades = (int*) calloc(n, sizeof(int));

        for (int i = 0, min_grade = 38; i < n; ++i)

            if (grades[i] < min_grade || is_zero_remainder(grades[i]))
                new_grades[i] = grades[i];
            else {
                int quocient = grades[i] / 5;
                int next_multiple_5 = (quocient + 1) * 5;
                int difference = next_multiple_5 - grades[i];
                new_grades[i] = difference < 3 ? next_multiple_5 : grades[i];
            }

        return new_grades;
    }

        bool is_zero_remainder(const int grade)
        {
            return grade % 5 == 0;
        }

    void print_array(const int *array, const int n)
    {
        for (int i = 0; i < n; printf("%d\n", array[i++]));
    }
