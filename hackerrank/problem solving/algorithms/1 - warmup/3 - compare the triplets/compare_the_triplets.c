// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true
// From C23

#include <stdio.h>
#include <stdlib.h>

int *read_int_array(int n);
int *compare_triplets(int array1[], int array2[], int n);
    int *prepare_output(int player1, int player2);

int main()
{
    constexpr int n = 3;
    int *array1 = read_int_array(n);
    int *array2 = read_int_array(n);

    int *result = compare_triplets(array1, array2, n);
    printf("%d %d", result[0], result[1]);
    free(array1);
    free(array2);
    free(result);

    return 0;
}

    int *read_int_array(const int n)
    {
        auto array = (int*) malloc(sizeof(int));
        for (int i = 0; i < n && scanf("%d", &array[i]); ++i);
        return array;
    }

    int *compare_triplets(int array1[], int array2[], int n)
    {
        int player1 = 0, player2 = 0;

        while (n--)
            if (array1[n] > array2[n])
                ++player1;
            else if (array2[n] > array1[n])
                ++player2;

        return prepare_output(player1, player2);
    }

        int *prepare_output(const int player1, const int player2)
        {
            constexpr int n = 2;
            auto result = (int*) malloc(n * sizeof(int));
            result[0] = player1;
            result[1] = player2;
            return result;
        }
