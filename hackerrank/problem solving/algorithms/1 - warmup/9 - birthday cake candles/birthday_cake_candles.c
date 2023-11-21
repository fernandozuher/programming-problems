// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int n);
int compare (const void *a, const void *b);
int birthday_cake_candles(int* candles, const int n);

int main()
{
    int n;
    scanf("%d", &n);

    int *array = read_int_array(n);

    qsort(array, n, sizeof(int), compare);
    printf("%d", birthday_cake_candles(array, n));

    return 0;
}

int* read_int_array(const int n)
{
    int *array = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < n; scanf("%d", &array[i++]));
    return array;
}

int compare (const void *a, const void *b)
{
    return (*(int*) a - * (int*) b);
}

int birthday_cake_candles(int* candles, const int n)
{
    int last_index = n - 1;
    int max_element = candles[last_index];
    int i;

    for (i = last_index; i >= 0 && candles[i] == max_element; --i);

    int minimum_index_max_element = i == -1 ? n : n - i - 1;
    return minimum_index_max_element;
}
