// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long count_in_repeated_string(const char* const string, const char letter, const long n_characters);
    long count(const char* const string, const long n, const char letter);

int main()
{
    const int string_max_size = 102; // 100 + \n + \0
    char string[string_max_size];
    long n_characters;

    fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1] = '\0';
    scanf("%ld", &n_characters);

    const char letter = 'a';
    printf("%ld\n", count_in_repeated_string(string, letter, n_characters));

    return 0;
}

    long count_in_repeated_string(const char* const string, const char letter, const long n_characters)
    {
        long n = strlen(string);
        ldiv_t division = ldiv(n_characters, n);
        long repeated_entire_string = division.quot;
        long n_substring = division.rem;

        long quantity = count(string, n, letter);
        quantity *= repeated_entire_string;
        quantity += count(string, n_substring, letter);

        return quantity;
    }

        long count(const char* const string, const long n, const char letter)
        {
            long quantity = 0;
            for (long i = 0; string[i] && i < n; quantity += string[i++] == letter);
            return quantity;
        }
