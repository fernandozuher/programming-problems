// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long count_in_repeated_string(const char *string, char letter, long long n_characters);
long long count_char(const char *string, long long n, char letter);

int main()
{
    constexpr int string_max_size = 102; // 100 + \n + \0
    char string[string_max_size];
    long long n_characters;

    fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1] = '\0';
    scanf("%lld", &n_characters);

    constexpr char letter = 'a';
    printf("%lld\n", count_in_repeated_string(string, letter, n_characters));

    return 0;
}

// n: length of string
// T: O(n)
// S: O(1) extra space
long long count_in_repeated_string(const char *string, char letter, long long n_characters)
{
    auto n = (long long) strlen(string);
    lldiv_t division = lldiv(n_characters, n);
    long long full_repeats = division.quot;
    long long n_substring = division.rem;

    long long count = count_char(string, n, letter);
    count *= full_repeats;
    return count + count_char(string, n_substring, letter);
}

long long count_char(const char *string, long long n, char letter)
{
    long long count = 0;
    for (long long i = 0; i < n; ++i)
        count += string[i] == letter;
    return count;
}
