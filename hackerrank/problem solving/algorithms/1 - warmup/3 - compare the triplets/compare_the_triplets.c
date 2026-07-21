// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_nums(int *arr, int n);
void compute_triplet_scores(const int *triplet_a, const int *triplet_b, int *out);

int main()
{
    constexpr int n = 3;
    constexpr int out_n = 2;
    int triplet_a[n], triplet_b[n], output[out_n];
    read_nums(triplet_a, n);
    read_nums(triplet_b, n);

    compute_triplet_scores(triplet_a, triplet_b, output);
    printf("%d %d\n", output[0], output[1]);

    return 0;
}

void read_nums(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of a and b = 3
// T: O(3) => O(1)
// S: O(1) extra space
void compute_triplet_scores(const int *triplet_a, const int *triplet_b, int *out)
{
    int score_a = 0, score_b = 0;

    for (int i = 0, n = 3; i < n; ++i)
        if (triplet_a[i] > triplet_b[i])
            ++score_a;
        else if (triplet_b[i] > triplet_a[i])
            ++score_b;

    out[0] = score_a;
    out[1] = score_b;
}
