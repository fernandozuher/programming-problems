// Source: https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_line_as_int_array(int n);
int birthday(const int* chocolate_squares, const int n, const int *day_month);

int main() {
    const int *array_size = read_line_as_int_array(1);
    const int n = array_size[0];
    const int *chocolate_squares = read_line_as_int_array(n);
    const int *day_month = read_line_as_int_array(2);

    const int result = birthday(chocolate_squares, n, day_month);
    printf("%d\n", result);

    return 0;
}

    int* read_line_as_int_array(const int n) {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &array[i]);
        return array;
    }

    int birthday(const int* chocolate_squares, const int n, const int *day_month) {
        int ways_bar_can_be_divided = 0;
        
        for (int i = 0, day = day_month[0], month = day_month[1], n2 = n - month + 1; i < n2; i++) {
            int sum = 0;
            for (int j = i, n3 = i + month; j < n3; sum += chocolate_squares[j++]);
            if (sum == day)
                ways_bar_can_be_divided++;
        }
        
        return ways_bar_can_be_divided;
    }
