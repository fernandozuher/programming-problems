// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long count_in_repeated_string(const char *str, char letter, long long n_chars);
long long count_char(const char *str, long long n, char letter);

int main()
{
    constexpr int string_max_size = 102; // 100 + \n + \0
    char str[string_max_size];
    long long n_chars;

    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';
    scanf("%lld", &n_chars);

    constexpr char letter = 'a';
    printf("%lld\n", count_in_repeated_string(str, letter, n_chars));

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

    long long count = count_char(str, n, letter);
    count *= full_repeats;
    return count + count_char(str, n_substr, letter);
}

long long count_char(const char *str, long long n, char letter)
{
    long long count = 0;
    for (long long i = 0; i < n; ++i)
        count += str[i] == letter;
    return count;
}
