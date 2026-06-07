// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>

long long array_manipulation(long long n, long long n_queries);
void populate_arr(long long *arr, long long n_queries);
long long max_sequential_sum(const long long *arr, long long n);

int main()
{
    long long n, n_queries;
    scanf("%lld %lld", &n, &n_queries);
    printf("%lld\n", array_manipulation(n, n_queries));
    return 0;
}

// T: O(n + n_queries)
// S: O(n) extra space
long long array_manipulation(long long n, long long n_queries)
{
    auto arr = (long long *) calloc(n + 2, sizeof(long long)); // +2 = 1-indexed array + range-end
    populate_arr(arr, n_queries);
    long long res = max_sequential_sum(arr, n + 2);

    free(arr);
    return res;
}

void populate_arr(long long *arr, long long n_queries)
{
    for (long long i = 0; i < n_queries; ++i) {
        long long b, e, summand;
        scanf("%lld %lld %lld", &b, &e, &summand);
        arr[b] += summand;
        arr[e + 1] -= summand;
    }
}

long long max_sequential_sum(const long long *arr, long long n)
{
    long long sum = 0, max = 0;
    for (long long i = 0; i < n; ++i) {
        sum += arr[i];
        max = sum > max ? sum : max;
    }
    return max;
}
