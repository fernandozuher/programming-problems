// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int beautiful_days(const int starting_day_number, const int ending_day_number, const int divisor);
    int generate_reverse_number(int number);
    bool is_day_beautiful(const int number, const int reverse_number, const int divisor);

int main()
{
    int starting_day_number, ending_day_number, divisor;
    scanf("%d %d %d", &starting_day_number, &ending_day_number, &divisor);
    printf("%d\n", beautiful_days(starting_day_number, ending_day_number, divisor));

    return 0;
}

    int beautiful_days(const int starting_day_number, const int ending_day_number, const int divisor)
    {
        int n_beautiful_days = 0;

        for (int number = starting_day_number; number <= ending_day_number; ++number) {
            int reverse_number = generate_reverse_number(number);
            if (is_day_beautiful(number, reverse_number, divisor))
                ++n_beautiful_days;
        }

        return n_beautiful_days;
    }

        int generate_reverse_number(int number)
        {
            int reverse_number = 0;
            for (; number > 0; number /= 10)
                reverse_number = (reverse_number * 10) + (number % 10);
            return reverse_number;
        }

        bool is_day_beautiful(const int number, const int reverse_number, const int divisor)
        {
            return abs(number - reverse_number) % divisor == 0;
        }
