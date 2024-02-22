// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int calculate_quantity_of_square_integers_in_range(const int begin, const int end);
    int find_first_square_integer(const int x);
    bool is_power_of_2_less_than_or_equal_to_limit(const int x, const int limit);
void print_array(const int* const array, const int n);

int main()
{
    int n;
    scanf("%d", &n);
    int output[n];

    for (int i = 0; i < n; ++i) {
        int begin, end;
        scanf("%d %d", &begin, &end);
        output[i] = calculate_quantity_of_square_integers_in_range(begin, end);
    }

    print_array(output, n);

    return 0;
}

    int calculate_quantity_of_square_integers_in_range(const int begin, const int end)
    {
        int first_square_integer = find_first_square_integer(begin);
        int squares = 0;
        for (int number = first_square_integer; is_power_of_2_less_than_or_equal_to_limit(number, end); ++number)
            ++squares;
        return squares;
    }

        int find_first_square_integer(const int x)
        {
            double square_root = sqrt(x);
            double integer_part = trunc(square_root);
            return square_root == integer_part ? integer_part : integer_part + 1;
        }

        bool is_power_of_2_less_than_or_equal_to_limit(const int x, const int limit)
        {
            return pow(x, 2) <= limit;
        }

    void print_array(const int* const array, const int n)
    {
        for (int i = 0; i < n; ++i)
            printf("%d\n", array[i]);
    }
