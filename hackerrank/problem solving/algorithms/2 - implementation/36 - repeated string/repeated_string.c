// Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

char* read_a_string();
unsigned long read_a_number();
unsigned long find_quantity_of_a_in_repeated_string(char* string, const unsigned long N_CHARACTERS);
    unsigned long find_quantity_of_a_in_original_string(char* string);
    unsigned long find_quantity_of_repeated_entire_string(char* string, const unsigned long N_CHARACTERS);
    unsigned long get_size_string(char* string);
    unsigned long find_quantity_of_remaining_a(char* string, const unsigned long N_CHARACTERS);
char* free_string(char* string);


int main() {
    char* input_string = read_a_string();
    const unsigned long N_CHARACTERS = read_a_number();

    const unsigned long QUANTITY_OF_A = find_quantity_of_a_in_repeated_string(input_string, N_CHARACTERS);
    printf("%lu\n", QUANTITY_OF_A);

    input_string = free_string(input_string);

    return 0;
}

    char* read_a_string() {
        const unsigned long INPUT_STRING_MAX_SIZE = 102;
        char* input_string = (char*) calloc(INPUT_STRING_MAX_SIZE, sizeof(char));
        scanf("%s", input_string);
        return input_string;
    }

    unsigned long read_a_number() {
        unsigned long number;
        scanf("%lu", &number);
        return number;
    }

    unsigned long find_quantity_of_a_in_repeated_string(char* string, const unsigned long N_CHARACTERS) {
        unsigned long quantity_of_a = find_quantity_of_a_in_original_string(string);
        quantity_of_a *= find_quantity_of_repeated_entire_string(string, N_CHARACTERS);
        quantity_of_a += find_quantity_of_remaining_a(string, N_CHARACTERS);

        return quantity_of_a;
    }

        unsigned long find_quantity_of_a_in_original_string(char* string) {
            unsigned long quantity_of_a = 0;

            for (; *string != '\0'; string++)
                if (*string == 'a')
                    quantity_of_a++;

            return quantity_of_a;
        }

        unsigned long find_quantity_of_repeated_entire_string(char* string, const unsigned long N_CHARACTERS) {
            const unsigned long SIZE_STRING = get_size_string(string);
            const unsigned long N_STRINGS = N_CHARACTERS / SIZE_STRING;
            return N_STRINGS;
        }

        unsigned long get_size_string(char* string) {
            unsigned long size = 0;
            while (*(string++) != '\0')
                size++;
            return size;
        }

        unsigned long find_quantity_of_remaining_a(char* string, const unsigned long N_CHARACTERS) {
            const unsigned long SIZE_STRING = get_size_string(string);
            const unsigned long N_REMAINING_CHARACTERS_OF_STRING = N_CHARACTERS % SIZE_STRING;
            unsigned long quantity_of_a = 0;

            for (unsigned long i = 0; i < N_REMAINING_CHARACTERS_OF_STRING; i++)
                if (*(string++) == 'a')
                    quantity_of_a++;

            return quantity_of_a;
        }

    char* free_string(char* string) {
        free(string);
        return NULL;
    }
