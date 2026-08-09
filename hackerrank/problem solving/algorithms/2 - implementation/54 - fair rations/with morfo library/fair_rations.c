// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

int min_loaves_to_satisfy_rules(const int *people_loaf_counts, int n);
bool is_odd(int n);

int main()
{
    morfo_skip_input_ln();
    size_t n;
    int *people_loaf_counts = morfo_readln(int, &n);

    int min_loaves = min_loaves_to_satisfy_rules(people_loaf_counts, n);
    min_loaves == -1 ? puts("NO") : printf("%d\n", min_loaves);

    free(people_loaf_counts);
    return 0;
}

// n: length of people_loaf_counts
// T: O(n)
// S: O(1) extra space
int min_loaves_to_satisfy_rules(const int *people_loaf_counts, int n)
{
    int loaves_given = 0;
    int counts = people_loaf_counts[0];

    for (int i = 1; i < n; ++i)
        if (is_odd(counts)) {
            loaves_given += 2;
            counts = people_loaf_counts[i] + 1;
        } else
            counts = people_loaf_counts[i];

    return is_odd(counts) ? -1 : loaves_given;
}

bool is_odd(int n)
{
    return n & 1;
}
