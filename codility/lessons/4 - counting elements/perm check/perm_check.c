// Source: https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/

#include <stdlib.h>

int compare (const void *a, const void *b);

int solution(int array[], int size)
{
    qsort(array, size, sizeof(int), compare);
    int i;
    for (i = 0; i < size && array[i] == i + 1; ++i);
    return i == size;
}

    int compare (const void *a, const void *b)
    {
        return (*(int*) a - *(int*) b);
    }
