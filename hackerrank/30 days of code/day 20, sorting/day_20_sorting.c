#include <stdio.h>

int bubble_sort(int *a, int n)
{
    int number_of_swaps = 0;

    for (int _ = 0; _ < n; ++_) {
        for (int j = 0, n2 = n - 1; j < n2; ++j)
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1], a[j + 1] = temp;
                number_of_swaps++;
            }

        if (!number_of_swaps)
            break;
    }
    return number_of_swaps;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int array[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &array[i]);

    printf("Array is sorted in %d swaps.", bubble_sort(array, n));
    printf("\nFirst Element: %d", array[0]);
    printf("\nLast Element: %d", array[n-1]);

    return 0;
}
