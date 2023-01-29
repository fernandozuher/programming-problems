// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

#include <stdbool.h>

int reduce_number_until_first_010(int number);
int calculate_temp_max_gap_in_parameter_and_return_reduced_number(int *temp_max_gap, int number);
    bool is_number_divisible_by_2(int number);
int max(const int number1, const int number2);


int solution(const int N) {
    int max_gap = 0;

    for (int number = reduce_number_until_first_010(N); number; number = reduce_number_until_first_010(number)) {
        int temp_max_gap = 0;

        number = calculate_temp_max_gap_in_parameter_and_return_reduced_number(&temp_max_gap, number);

        if (number)
            max_gap = max(temp_max_gap, max_gap);
    }

    return max_gap;
}

    int reduce_number_until_first_010(int number) {
        while (number && is_number_divisible_by_2(number))
            number /= 2;

        while (number && !is_number_divisible_by_2(number))
            number /= 2;

        return number;
    }

    int calculate_temp_max_gap_in_parameter_and_return_reduced_number(int *temp_max_gap, int number) {
        while (number && is_number_divisible_by_2(number)) {
            (*temp_max_gap)++;
            number /= 2;
        }
        return number;
    }

        bool is_number_divisible_by_2(const int number) {
            return number % 2 == 0;
        }

    int max(const int number1, const int number2) {
        return number1 > number2 ? number1 : number2;
    }
