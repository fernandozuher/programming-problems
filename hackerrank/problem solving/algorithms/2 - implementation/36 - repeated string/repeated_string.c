// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long count_in_repeated_string(const char *string, char letter, long n_characters);
long count(const char *string, long n, char letter);

int main()
{
    constexpr int string_max_size = 102; // 100 + \n + \0
    char string[string_max_size];
    long n_characters;

    fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1] = '\0';
    scanf("%ld", &n_characters);

    constexpr char letter = 'a';
    printf("%ld\n", count_in_repeated_string(string, letter, n_characters));

    return 0;
}

long count_in_repeated_string(const char *string, char letter, long n_characters)
{
    long n = strlen(string);
    ldiv_t division = ldiv(n_characters, n);
    long full_repeats = division.quot;
    long n_substring = division.rem;

    long quantity = count(string, n, letter);
    quantity *= full_repeats;
    return quantity + count(string, n_substring, letter);
}

long count(const char *string, long n, char letter)
{
    long quantity = 0;
    for (long i = 0; string[i] && i < n; ++i)
        quantity += string[i] == letter;
    return quantity;
}
