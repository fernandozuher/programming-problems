// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int n);
int birthday(const int* const chocolate_squares, const int n, const int* const day_month);

int main()
{
    int n;
    scanf("%d", &n);
    int *chocolate_squares = read_int_array(n);
    const int n_day_month = 2;
    int *day_month = read_int_array(n_day_month);

    printf("%d\n", birthday(chocolate_squares, n, day_month));

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int birthday(const int* const chocolate_squares, const int n, const int* const day_month)
    {
        int ways_bar_can_be_divided = 0;

        for (int i = 0, day = day_month[0], month = day_month[1], n2 = n - month + 1; i < n2; ++i) {
            int sum = 0;

            for (int j = i, n3 = i + month; j < n3; sum += chocolate_squares[j++]);
            if (sum == day)
                ++ways_bar_can_be_divided;
        }

        return ways_bar_can_be_divided;
    }
