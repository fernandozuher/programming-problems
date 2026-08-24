// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "morfo/collections.h"
#include "morfo/io.h"

long long count_in_repeated_string(const char *str, char letter, long long n_chars);

int main()
{
    char *str = morfo_read(char *);
    long long n_chars = morfo_read(long long);

    constexpr char letter = 'a';
    printf("%lld\n", count_in_repeated_string(str, letter, n_chars));

    free(str);
    return 0;
}

// n: length of str
// T: O(n)
// S: O(1) extra space
long long count_in_repeated_string(const char *str, char letter, long long n_chars)
{
    auto n = (long long) strlen(str);
    lldiv_t division = lldiv(n_chars, n);
    long long full_repeats = division.quot;
    long long n_substr = division.rem;

    long long count = (long long) morfo_count(str, (size_t) n, letter);
    count *= full_repeats;
    return count + (long long) morfo_count(str, (size_t) n_substr, letter);
}
