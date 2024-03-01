// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long find_quantity_of_character_in_repeated_string(const char* const string, const char character, const unsigned long n_letters);
    unsigned long find_quantity_of_character_in_string(const char *string, const char character);
    unsigned long quantity_of_repeated_entire_string(const char* const string, const unsigned long n_letters);
    unsigned long find_quantity_of_character_in_remaining_characters(const char* const string, const char character, const unsigned long n_letters);

int main()
{
    const int string_max_size = 102;
    char string[string_max_size];
    unsigned long n_letters;
    scanf("%s %lu", string, &n_letters);

    const char character = 'a';
    printf("%lu\n", find_quantity_of_character_in_repeated_string(string, character, n_letters));

    return 0;
}

    unsigned long find_quantity_of_character_in_repeated_string(const char* const string, const char character, const unsigned long n_letters)
    {
        unsigned long quantity_of_character = find_quantity_of_character_in_string(string, character);
        quantity_of_character *= quantity_of_repeated_entire_string(string, n_letters);
        quantity_of_character += find_quantity_of_character_in_remaining_characters(string, character, n_letters);
        return quantity_of_character;
    }

        unsigned long find_quantity_of_character_in_string(const char *string, const char character)
        {
            unsigned long count = 0;
            while (*string)
                if (*string++ == character)
                    ++count;
            return count;
        }

        unsigned long quantity_of_repeated_entire_string(const char* const string, const unsigned long n_letters)
        {
            return n_letters / strlen(string);
        }

        unsigned long find_quantity_of_character_in_remaining_characters(const char* const string, const char character, const unsigned long n_letters)
        {
            unsigned long n_remaining_characters_of_string = n_letters % strlen(string);

            if (n_remaining_characters_of_string == 0)
                return 0;

            char sub_string[n_remaining_characters_of_string + 1];

            strncpy(sub_string, string, n_remaining_characters_of_string);
            sub_string[n_remaining_characters_of_string] = '\0';

            return find_quantity_of_character_in_string(sub_string, character);
        }
