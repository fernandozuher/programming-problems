// https://www.hackerrank.com/challenges/30-sorting/problem?isFullScreen=true

#include <stdio.h>

int bubble_sort(int *array, int n);
    void swap(int *array, const int i);

int main()
{
    int n;
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &array[i]);

    printf("Array is sorted in %d swaps.", bubble_sort(array, n));
    printf("\nFirst Element: %d", array[0]);
    printf("\nLast Element: %d", array[n - 1]);

    return 0;
}

    int bubble_sort(int *array, int n)
    {
        int number_of_swaps = 0;

        while (--n) {
            for (int i = 0; i < n; ++i)
                if (array[i] > array[i + 1]) {
                    swap(array, i);
                    ++number_of_swaps;
                }

            if (!number_of_swaps)
                break;
        }

        return number_of_swaps;
    }

        void swap(int *array, const int i)
        {
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
