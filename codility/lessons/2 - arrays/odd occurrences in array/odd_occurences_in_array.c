// Source: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

#include <stdbool.h>

int compare (const void *a, const void *b);

int solution(int A[], int N) {
    qsort(A, N, sizeof(int), compare);

    int unpaired_element = A[0];
    bool is_element_paired = false;

    for (int i = 1; i < N; i++)
        if (A[i] == unpaired_element)
            is_element_paired = !is_element_paired;
        else if (is_element_paired) {
            is_element_paired = false;
            unpaired_element = A[i];
        }
        else
            break;

    return unpaired_element;
}

    int compare (const void *a, const void *b) {
        return ( *(int*)a - * (int*)b );
    }