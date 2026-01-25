// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

#include <stdio.h>

#define MAX_DIGITS_OF_FACTORIAL_100 158

void factorial(int n, int *res, int *size);
void multiply_array_with_number(int *arr, int *size, int number);
void add_remaining_carry_to_array(int carry, int *arr, int *size);
void print_factorial(const int *arr, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int res[MAX_DIGITS_OF_FACTORIAL_100];
    int size = 0;

    factorial(n, res, &size);
    print_factorial(res, size);

    return 0;
}

// T: O(n)
// S: O(158) = O(1) extra space
void factorial(int n, int *res, int *size)
{
    res[0] = 1;
    *size = 1;
    for (int i = 1; i <= n; ++i)
        multiply_array_with_number(res, size, i);
}

void multiply_array_with_number(int *arr, int *size, int number)
{
    int carry = 0;
    for (int i = 0; i < *size; ++i) {
        int product = arr[i] * number + carry;
        arr[i] = product % 10;
        carry = product / 10;
    }

    add_remaining_carry_to_array(carry, arr, size);
}

void add_remaining_carry_to_array(int carry, int *arr, int *size)
{
    for (; carry; carry /= 10) {
        arr[*size] = carry % 10;
        ++(*size);
    }
}

void print_factorial(const int *arr, int n)
{
    for (int i = n - 1; i >= 0; --i)
        printf("%d", arr[i]);
    puts("");
}
