// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

#include <stdio.h>

int save_the_prisoner(const int prisoners, const int sweets, const int chair_number_to_begin);
void print_array(const int* const array, const int n);

int main()
{
    int n;
    scanf("%d", &n);
    int prisoners_chair_number_to_warn[n];

    for (int i = 0; i < n; ++i) {
        int prisoners, sweets, chair_number_to_begin;
        scanf("%d %d %d", &prisoners, &sweets, &chair_number_to_begin);
        prisoners_chair_number_to_warn[i] = save_the_prisoner(prisoners, sweets, chair_number_to_begin);
    }

    print_array(prisoners_chair_number_to_warn, n);

    return 0;
}

    int save_the_prisoner(const int prisoners, const int sweets, const int chair_number_to_begin)
    {
        int prisoner_chair_number_to_warn = chair_number_to_begin + (sweets - 1);
        int x = prisoner_chair_number_to_warn;

        if (x > prisoners) {
            x %= prisoners;
            if (x == 0)
                x = prisoners;
        }

        return x;
    }

    void print_array(const int* const array, const int n)
    {
        for (int i = 0; i < n; printf("%d\n", array[i++]));
    }