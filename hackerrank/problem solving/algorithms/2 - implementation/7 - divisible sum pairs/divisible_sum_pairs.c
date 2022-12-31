// Source: https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_line_as_int_array(int n);
int divisible_sum_pairs(const int* numbers, const int n, const int k);
int compare (const void * a, const void * b);

int main() {
    const int *input1 = read_line_as_int_array(2);
    const int n = input1[0];
    const int k = input1[1];
    int *numbers = read_line_as_int_array(n);

    qsort(numbers, n, sizeof(int), compare);

    const int result = divisible_sum_pairs(numbers, n, k);
    printf("%d\n", result);

    return 0;
}

    int* read_line_as_int_array(const int n) {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &array[i]);
        return array;
    }

    int compare (const void * a, const void * b) {
        return (*(int*)a - *(int*)b);
    }

    int divisible_sum_pairs(const int *numbers, const int n, const int k) {
        int n_divisible_sum_pairs = 0;
        
        for (int i = 0, n1 = n - 1; i < n1; i++)
            for (int j = i + 1; j < n; j++)
                if (numbers[i] <= numbers[j] && !((numbers[i] + numbers[j]) % k))
                    n_divisible_sum_pairs++;
        
        return n_divisible_sum_pairs;
    }
