// Source: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int read_one_int();
int beautiful_days(const int starting_day_number, const int ending_day_number, const int divisor);
    int generate_reverse_number(int number);
    bool is_day_beautiful(const int number, const int reverse_number, const int divisor);


int main() {
    const int starting_day_number = read_one_int();
    const int ending_day_number = read_one_int();
    const int divisor = read_one_int();

    const int n_beautiful_days = beautiful_days(starting_day_number, ending_day_number, divisor);

    printf("%d", n_beautiful_days);

    return 0;
}

    int read_one_int() {
        int number;
        scanf("%d ", &number);
        return number;
    }

    int beautiful_days(const int starting_day_number, const int ending_day_number, const int divisor) {
        int n_beautiful_days = 0;

        for (int number = starting_day_number; number <= ending_day_number; number++) {
            const int reverse_number = generate_reverse_number(number);

            if (is_day_beautiful(number, reverse_number, divisor))
                n_beautiful_days++;
        }

        return n_beautiful_days;
    }

        int generate_reverse_number(int number) {
            int reverse_number = 0;
            for (; number > 0; number /= 10)
                reverse_number = (reverse_number * 10) + (number % 10);
            return reverse_number;
        }

        bool is_day_beautiful(const int number, const int reverse_number, const int divisor) {
            bool beautiful_day = abs(number - reverse_number) % divisor == 0;
            return beautiful_day;
        }
