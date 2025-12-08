// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long count_in_repeated_string(const char *string, char letter, long long n_characters);
long long count(const char *string, long long n, char letter);

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

long long count_in_repeated_string(const char *string, char letter, long long n_characters)
{
    auto n = (long long) strlen(string);
    lldiv_t division = lldiv(n_characters, n);
    long long full_repeats = division.quot;
    long long n_substring = division.rem;

    long long quantity = count(string, n, letter);
    quantity *= full_repeats;
    return quantity + count(string, n_substring, letter);
}

long long count(const char *string, long long n, char letter)
{
    long long quantity = 0;
    for (long long i = 0; string[i] && i < n; ++i)
        quantity += string[i] == letter;
    return quantity;
}
