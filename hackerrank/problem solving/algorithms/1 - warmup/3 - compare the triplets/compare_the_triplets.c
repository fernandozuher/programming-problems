// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int size);
int* compare_triplets(const int const *array1, const int const *array2, int size);
    int* prepare_output(const int player1, const int player2);
int* free_array(int *array);

int main()
{
    const int size = 3;
    int *array1 = read_int_array(size);
    int *array2 = read_int_array(size);

    int *result = compare_triplets(array1, array2, size);
    array1 = free_array(array1);
    array2 = free_array(array2);

    printf("%d %d\n", result[0], result[1]);
    result = free_array(result);

    return 0;
}

    int* read_int_array(const int size)
    {
        int *array = (int*) calloc(size, sizeof(int));
        for (int i = 0; i < size; scanf("%d", &array[i++]));
        return array;
    }

    int* compare_triplets(const int const *array1, const int const *array2, int size)
    {
        int player1 = 0, player2 = 0;

        while (size--)
            if (array1[size] > array2[size])
                player1++;
            else if (array1[size] < array2[size])
                player2++;

        return prepare_output(player1, player2);
    }

        int* prepare_output(const int player1, const int player2)
        {
            const int size_result = 2;
            int *result = (int*) calloc(size_result, sizeof(int));
            result[0] = player1;
            result[1] = player2;
            return result;
        }

    int* free_array(int *array)
    {
        free(array);
        return NULL;
    }
