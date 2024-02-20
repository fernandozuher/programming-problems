// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool append_and_delete(const char initial_string[], const char final_string[], int operations);
    int find_common_prefix_size(const char* initial_string, const char* final_string);
    bool are_operations_suitable_to_replace_string(const int operations, const int COMMON_PREFIX_SIZE_BETWEEN_STRINGS);
        bool are_operations_bigger_than_zero_and_odd(const int operations);
        bool are_not_operations_enough_to_remove_and_replace_common_prefix(const int operations, const int COMMON_PREFIX_SIZE_BETWEEN_STRINGS);

int main()
{
    const int max_size = 101;
    char initial_string[max_size], final_string[max_size];
    scanf("%s %s", initial_string, final_string);

    int operations;
    scanf("%d", &operations);

    append_and_delete(initial_string, final_string, operations) ? puts("Yes") : puts("No");

    return 0;
}

    bool append_and_delete(const char initial_string[], const char final_string[], int operations)
    {
        int initial_string_size = strlen(initial_string);
        int final_string_size = strlen(final_string);

        int common_prefix_size_between_strings = find_common_prefix_size(initial_string, final_string);
        int size_of_different_characters_from_initial_string = initial_string_size - common_prefix_size_between_strings;
        int size_of_different_characters_from_final_string = final_string_size - common_prefix_size_between_strings;

        int minimal_quantity_of_operations_to_replace_string = size_of_different_characters_from_initial_string + size_of_different_characters_from_final_string;
        operations -= minimal_quantity_of_operations_to_replace_string;

        return are_operations_suitable_to_replace_string(operations, common_prefix_size_between_strings);
    }

        int find_common_prefix_size(const char* initial_string, const char* final_string)
        {
            int size = 0;
            while (*initial_string && *final_string && *initial_string++ == *final_string++)
                ++size;
            return size;
        }

        bool are_operations_suitable_to_replace_string(const int operations, const int common_prefix_size_between_strings)
        {
            if (operations < 0 ||
                    (are_operations_bigger_than_zero_and_odd(operations) &&
                     are_not_operations_enough_to_remove_and_replace_common_prefix(operations, common_prefix_size_between_strings)))
                return false;
            return true;
        }

            bool are_operations_bigger_than_zero_and_odd(const int operations)
            {
                return operations > 0 && operations & 1;
            }

            bool are_not_operations_enough_to_remove_and_replace_common_prefix(const int operations, const int common_prefix_size_between_strings)
            {
                return operations < common_prefix_size_between_strings * 2;
            }
