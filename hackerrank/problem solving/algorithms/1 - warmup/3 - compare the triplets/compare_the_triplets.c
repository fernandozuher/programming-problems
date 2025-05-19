// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true
// C23

#include <stdio.h>

typedef struct {
    int *array;
    int size;
} array_t;

void read_input(const array_t array);
void compare_triplets(const array_t triplet_a, const array_t triplet_b, const array_t result);

int main()
{
    constexpr int triplet_size = 3;
    constexpr int result_size = 3;
    int input_a[triplet_size], input_b[triplet_size], output[result_size];
    array_t triplet_a = {input_a, triplet_size};
    array_t triplet_b = {input_b, triplet_size};
    array_t result = {output, result_size};

    read_input(triplet_a);
    read_input(triplet_b);
    compare_triplets(triplet_a, triplet_b, result);
    printf("%d %d\n", result.array[0], result.array[1]);

    return 0;
}

void read_input(const array_t array)
{
    for (int i = 0, n = array.size; i < n; ++i)
        scanf("%d", &array.array[i]);
}

void compare_triplets(const array_t triplet_a, const array_t triplet_b, const array_t result)
{
    int score_a = 0, score_b = 0;

    for (int i = 0, n = triplet_a.size; i < n; ++i)
        if (triplet_a.array[i] > triplet_b.array[i])
            ++score_a;
        else if (triplet_b.array[i] > triplet_a.array[i])
            ++score_b;

    result.array[0] = score_a;
    result.array[1] = score_b;
}
