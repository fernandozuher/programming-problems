// Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* read_a_string();
    char* remove_new_line_character_from_string(char* string);
int get_string_size(char* string);
int read_a_number();

bool append_and_delete(char* initial_string, char* final_string, int number_of_operations);
    int find_common_prefix_size(char* initial_string, char* final_string);
    bool are_operations_suitable_to_replace_string(const int NUMBER_OF_OPERATIONS, const int COMMON_PREFIX_SIZE_BETWEEN_STRINGS);
        bool are_operations_bigger_than_zero_and_odd(const int NUMBER_OF_OPERATIONS);
        bool are_not_operations_enough_to_remove_and_replace_common_prefix(const int NUMBER_OF_OPERATIONS, const int COMMON_PREFIX_SIZE_BETWEEN_STRINGS);

void* free_string(char* string);


int main() {
    char* initial_string = read_a_string();
    char* final_string = read_a_string();
    const int NUMBER_OF_OPERATIONS = read_a_number();

    bool response = append_and_delete(initial_string, final_string, NUMBER_OF_OPERATIONS);
    response ? puts("Yes") : puts("No");

    initial_string = free_string(initial_string);
    final_string = free_string(final_string);

    return 0;
}

    char* read_a_string() {
        const int MAX_SIZE_OF_STRING = 102;
        char* string = (char*) calloc(MAX_SIZE_OF_STRING, sizeof(char));

        fgets(string, MAX_SIZE_OF_STRING, stdin);
        string = remove_new_line_character_from_string(string);

        return string;
    }

        char* remove_new_line_character_from_string(char* string) {
            int size = get_string_size(string);
            string[size - 1] = '\0';
            return string;
        }

    int get_string_size(char* string) {
        int size;
        for (size = 0; *string != '\0'; string++)
            size++;
        return size;
    }

    int read_a_number() {
        int number;
        scanf("%d", &number);
        return number;
    }

    bool append_and_delete(char* initial_string, char* final_string, int number_of_operations) {
        const int INITIAL_STRING_SIZE = get_string_size(initial_string);
        const int FINAL_STRING_SIZE = get_string_size(final_string);

        const int COMMON_PREFIX_SIZE_BETWEEN_STRINGS = find_common_prefix_size(initial_string, final_string);
        const int SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING = INITIAL_STRING_SIZE - COMMON_PREFIX_SIZE_BETWEEN_STRINGS;
        const int SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING = FINAL_STRING_SIZE - COMMON_PREFIX_SIZE_BETWEEN_STRINGS;

        const int MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING = SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING + SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING;
        number_of_operations -= MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING;

        return are_operations_suitable_to_replace_string(number_of_operations, COMMON_PREFIX_SIZE_BETWEEN_STRINGS);
    }

        int find_common_prefix_size(char* initial_string, char* final_string) {
            int size = 0;
            while (*initial_string != '\0' && *final_string != '\0' && *(initial_string++) == *(final_string++))
                size++;
            return size;
        }

        bool are_operations_suitable_to_replace_string(const int NUMBER_OF_OPERATIONS, const int COMMON_PREFIX_SIZE_BETWEEN_STRINGS) {
            if (NUMBER_OF_OPERATIONS < 0 || 
                (are_operations_bigger_than_zero_and_odd(NUMBER_OF_OPERATIONS) &&
                     are_not_operations_enough_to_remove_and_replace_common_prefix(NUMBER_OF_OPERATIONS, COMMON_PREFIX_SIZE_BETWEEN_STRINGS)))
                return false;
            return true;
        }

            bool are_operations_bigger_than_zero_and_odd(const int NUMBER_OF_OPERATIONS) {
                return NUMBER_OF_OPERATIONS > 0 && NUMBER_OF_OPERATIONS % 2 == 1;
            }

            bool are_not_operations_enough_to_remove_and_replace_common_prefix(const int NUMBER_OF_OPERATIONS, const int COMMON_PREFIX_SIZE_BETWEEN_STRINGS) {
                return NUMBER_OF_OPERATIONS < COMMON_PREFIX_SIZE_BETWEEN_STRINGS * 2;
            }

    void* free_string(char* string) {
        free(string);
        return NULL;
    }
