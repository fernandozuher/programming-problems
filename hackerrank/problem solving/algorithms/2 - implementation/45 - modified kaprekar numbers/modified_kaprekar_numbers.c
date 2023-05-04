// Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUANTITY_OF_KAPREKAR_NUMBERS 100
#define MAX_SIZE_OF_SQUARE_NUMBER_IN_STRING 15

int read_a_number();

int** find_kaprekar_numbers_in_range(const int lower_limit, const int upper_limit);
    int** initialize_output();
    int calculate_potential_kaprekar_number(const int number);
        char* calculate_big_square_number(const int number);
        int calculate_length_of_number_in_string(const int number);
        char* get_left_number_in_string(const char* square_number_in_string, const int length_of_number_in_string);
        char* get_right_number_in_string(const char* square_number_in_string, const int length_of_number_in_string);
        int sum_numbers_in_strings(const char* left_number_in_string, const char* right_number_in_string);
        char* free_char_array(char* array);

void print_output(int** array);
int** free_bidimensional_int_array(int** array, const int size);

int main()
{
    const int lower_limit = read_a_number();
    const int upper_limit = read_a_number();

    int** output = find_kaprekar_numbers_in_range(lower_limit, upper_limit);
    print_output(output);

    output = free_bidimensional_int_array(output, 2);

    return 0;
}

    int read_a_number()
    {
        int number;
        scanf("%d", &number);
        return number;
    }

    int** find_kaprekar_numbers_in_range(const int lower_limit, const int upper_limit)
    {
        int** kaprekar_numbers = initialize_output();
        int kaprekar_numbers_size = 0;

        for (int number = lower_limit; number <= upper_limit; number++)
        {
            const int potential_kaprekar_number = calculate_potential_kaprekar_number(number);
            if (number == potential_kaprekar_number)
                kaprekar_numbers[0][kaprekar_numbers_size++] = number;
        }

        kaprekar_numbers[1][0] = kaprekar_numbers_size;

        return kaprekar_numbers;
    }

        int** initialize_output()
        {
            int** kaprekar_numbers = (int**) calloc(2, sizeof(int*));
            kaprekar_numbers[0] = (int*) calloc(MAX_QUANTITY_OF_KAPREKAR_NUMBERS, sizeof(int));
            kaprekar_numbers[1] = (int*) calloc(1, sizeof(int));
            return kaprekar_numbers;
        }

        int calculate_potential_kaprekar_number(const int number)
        {
            char* square_number_in_string = calculate_big_square_number(number);
            const int length_of_number_in_string = calculate_length_of_number_in_string(number);

            char* left_number_in_string = get_left_number_in_string(square_number_in_string, length_of_number_in_string);
            char* right_number_in_string = get_right_number_in_string(square_number_in_string, length_of_number_in_string);

            const int potential_kaprekar_number = sum_numbers_in_strings(left_number_in_string, right_number_in_string);

            square_number_in_string = free_char_array(square_number_in_string);
            left_number_in_string = free_char_array(left_number_in_string);
            right_number_in_string = free_char_array(right_number_in_string);

            return potential_kaprekar_number;
        }

            char* calculate_big_square_number(const int number)
            {
                const unsigned long long squared_number = (unsigned long long) number * (unsigned long long) number;
                char* square_number_in_string = (char*) calloc(MAX_SIZE_OF_SQUARE_NUMBER_IN_STRING, sizeof(char));
                sprintf(square_number_in_string, "%llu", squared_number);
                return square_number_in_string;
            }

            int calculate_length_of_number_in_string(const int number)
            {
                char number_in_string[MAX_SIZE_OF_SQUARE_NUMBER_IN_STRING];
                sprintf(number_in_string, "%d", number);
                const int length_of_number_in_string = strlen(number_in_string);
                return length_of_number_in_string;
            }

            char* get_left_number_in_string(const char* square_number_in_string, const int length_of_number_in_string)
            {
                const int digits_to_skip = 0;
                const int digits_to_take = strlen(square_number_in_string) - length_of_number_in_string;

                char* number_in_string = (char*) calloc(10, sizeof(char));
                strncpy(number_in_string, square_number_in_string + digits_to_skip, digits_to_take);

                return number_in_string;
            }

            char* get_right_number_in_string(const char* square_number_in_string, const int length_of_number_in_string)
            {
                const int digits_to_skip = strlen(square_number_in_string) - length_of_number_in_string;
                const int digits_to_take = strlen(square_number_in_string) - digits_to_skip;

                char* number_in_string = (char*) calloc(10, sizeof(char));
                strncpy(number_in_string, square_number_in_string + digits_to_skip, digits_to_take);

                return number_in_string;
            }

            int sum_numbers_in_strings(const char* left_number_in_string, const char* right_number_in_string)
            {
                if (strlen(left_number_in_string) > 0 && strlen(right_number_in_string) > 0)
                    return atoi(left_number_in_string) + atoi(right_number_in_string);
                else if (strlen(left_number_in_string) == 0)
                    return atoi(right_number_in_string);
                else if (strlen(right_number_in_string) == 0)
                    return atoi(left_number_in_string);
                return 0;
            }

            char* free_char_array(char* array)
            {
                free(array);
                return NULL;
            }

    void print_output(int** array)
    {
        const int size = array[1][0];
        if (size > 0)
            for (int i = 0; i < size; i++)
                printf("%d ", array[0][i]);
        else
            puts("INVALID RANGE");
    }

    int** free_bidimensional_int_array(int** array, const int size)
    {
        for (int i = 0; i < size; i++)
            free(array[i]);
        free(array);
        return NULL;
    }
