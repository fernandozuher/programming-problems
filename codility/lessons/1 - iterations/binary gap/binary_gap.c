// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

#include <stdbool.h>

int reduce_number_until_first_10(int number);
int count_binary_gap_in_parameter_and_return_reduced_number(int *temp_longest_binary_gap, int number);
    bool is_number_divisible_by_2(int number);

bool is_not_reduced_number_0(const int NUMBER);
int max(const int NUMBER1, const int NUMBER2);


int solution(const int N) {
    int longest_binary_gap = 0;

    for (int number = reduce_number_until_first_10(N); number; number = reduce_number_until_first_10(number)) {
        int temp_longest_binary_gap = 0;

        number = count_binary_gap_in_parameter_and_return_reduced_number(&temp_longest_binary_gap, number);

        if (is_not_reduced_number_0(number))
            longest_binary_gap = max(temp_longest_binary_gap, longest_binary_gap);
    }

    return longest_binary_gap;
}

    int reduce_number_until_first_10(int number) {
        while (number && is_number_divisible_by_2(number))
            number /= 2;

        while (number && !is_number_divisible_by_2(number))
            number /= 2;

        return number;
    }

    int count_binary_gap_in_parameter_and_return_reduced_number(int *temp_longest_binary_gap, int number) {
        while (number && is_number_divisible_by_2(number)) {
            (*temp_longest_binary_gap)++;
            number /= 2;
        }
        return number;
    }

        bool is_number_divisible_by_2(const int NUMBER) {
            return NUMBER % 2 == 0;
        }

    bool is_not_reduced_number_0(const int NUMBER) {
        return NUMBER;
    }

    int max(const int NUMBER1, const int NUMBER2) {
        return NUMBER1 > NUMBER2 ? NUMBER1 : NUMBER2;
    }
