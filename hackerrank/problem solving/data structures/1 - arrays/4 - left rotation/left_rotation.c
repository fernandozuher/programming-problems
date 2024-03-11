// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* read_int_array(const int n);
int* rotate(const int* const array, const int size, const int rotate_by);
void print_array(const int* const array, const int n);

int main()
{
    int n, rotate_by;
    scanf("%d %d", &n, &rotate_by);
    int *array = read_int_array(n);

    if (rotate_by > n - 1)
        rotate_by %= n;

    int *rotated = rotate(array, n, rotate_by);
    print_array(rotated, n);

    free(array);
    free(rotated);
    array = rotated = NULL;

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; ++i)
            scanf("%d", &array[i]);
        return array;
    }

    int* rotate(const int* const array, const int size, const int rotate_by)
    {
        int *rotated = (int*) calloc(size, sizeof(int));
        memmove(rotated, array + rotate_by, (size - rotate_by) * sizeof(int));
        memmove(rotated + (size - rotate_by), array, rotate_by * sizeof(int));
        return rotated;
    }

    void print_array(const int* const array, const int n)
    {
        for (int i = 0; i < n; ++i)
            printf("%d ", array[i]);
    }
