// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

#include <stdio.h>

int birthday_cake_candles(int n);

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", birthday_cake_candles(n));

    return 0;
}

    int birthday_cake_candles(const int n)
    {
        int max_element_quantity = 0;

        for (int i = 0, max_element = 0, x; i < n && scanf("%d", &x); ++i)
            if (x > max_element) {
                max_element = x;
                max_element_quantity = 1;
            }
            else if (x == max_element)
                ++max_element_quantity;
    
        return max_element_quantity;
    }
