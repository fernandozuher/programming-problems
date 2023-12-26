// Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int n);
char* kangaroo(const int *array);

int main()
{
    const int size = 4;
    int *array = read_int_array(size);
    puts(kangaroo(array));

    free(array);
    array = NULL;

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    char* kangaroo(const int *array)
    {
        int x1 = array[0];
        int v1 = array[1];
        int x2 = array[2];
        int v2 = array[3];

        if (v2 >= v1)
            return "NO";
        for (; x1 < x2; x1 += v1, x2 += v2);
        return x1 == x2 ? "YES" : "NO";
    }
