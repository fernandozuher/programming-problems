// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true
// From C23 onwards: built-in bool

#include <stdio.h>

int find_max_length_of_ones(int n);
bool is_bit_on(const int n);
int max(const int a, const int b);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", find_max_length_of_ones(n));
    return 0;
}

int find_max_length_of_ones(int n)
{
    int max_length = 0;
    int current_length = 0;
    for (; n > 0; n >>= 1) {
        if (is_bit_on(n))
            ++current_length;
        else {
            max_length = max(max_length, current_length);
            current_length = 0;
        }
    }
    max_length = max(max_length, current_length);
    return max_length;
}

bool is_bit_on(const int n)
{
    return n & 1;
}

int max(const int a, const int b)
{
    return a >= b ? a : b;
}
