// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* reverse_array(int* const array, const int n);

int main()
{
    int n;
    scanf("%d", &n);
    int *array = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &array[i]);

    array = reverse_array(array, n);

    for (int i = 0; i < n; ++i)
        printf("%d ", array[i]);

    return 0;
}

    int* reverse_array(int* const array, const int n)
    {
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        return array;
    }
