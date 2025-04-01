// https://www.hackerrank.com/challenges/30-sorting/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
} array_t;

array_t *read_input();
int bubble_sort(array_t *numbers);
void sort_slice(int *a, int *end, int *total_swaps);
void swap_adjacent(int *a, int i);
array_t *free_array_t(array_t *numbers);

int main()
{
    array_t *numbers = read_input();
    int n_swaps = bubble_sort(numbers);

    printf("Array is sorted in %d swaps.", n_swaps);
    printf("\nFirst Element: %d", numbers->data[0]);
    printf("\nLast Element: %d", numbers->data[numbers->size - 1]);

    numbers = free_array_t(numbers);
    return 0;
}

array_t *read_input()
{
    int n;
    scanf("%d", &n);
    auto a = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    auto numbers = (array_t *) malloc(sizeof(array_t));
    numbers->data = a;
    numbers->size = n;
    return numbers;
}

int bubble_sort(array_t *numbers)
{
    int total_swaps = 0;
    for (int *a = numbers->data, end = numbers->size; end > 0;)
        sort_slice(a, &end, &total_swaps);
    return total_swaps;
}

void sort_slice(int *a, int *end, int *total_swaps)
{
    int new_end = 0;
    int n_swaps = 0;

    for (int i = 0, n = *end - 1; i < n; ++i) {
        if (a[i] > a[i + 1]) {
            swap_adjacent(a, i);
            new_end = i + 1;
            n_swaps += 1;
        }
    }

    *end = new_end;
    *total_swaps += n_swaps;
}

void swap_adjacent(int *a, int i)
{
    int temp = a[i];
    a[i] = a[i + 1];
    a[i + 1] = temp;
}

array_t *free_array_t(array_t *numbers)
{
    free(numbers->data);
    free(numbers);
    return nullptr;
}
