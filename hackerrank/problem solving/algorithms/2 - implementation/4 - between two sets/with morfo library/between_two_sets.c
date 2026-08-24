// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"
#include "morfo/math.h"

int between_two_sets(const int *a, size_t n1, const int *b, size_t n2);

int main()
{
    morfo_skip_input_ln();
    size_t n1, n2;
    int *a = morfo_readln(int, &n1);
    int *b = morfo_readln(int, &n2);
    printf("%d\n", between_two_sets(a, n1, b, n2));
    free(a);
    free(b);
    return 0;
}

// n1, n2: length of a, b
// k: number of multiples tested = gcd_of_b / lcm_of_a
// T: O(n1 + n2 + k)
// S: O(1) extra space
int between_two_sets(const int *a, size_t n1, const int *b, size_t n2)
{
    int lcm_of_a = morfo_lcm(a, n1);
    int gcd_of_b = morfo_gcd(b, n2);

    int count = 0;
    for (int i = lcm_of_a; i <= gcd_of_b; i += lcm_of_a)
        if (gcd_of_b % i == 0)
            ++count;
    return count;
}
