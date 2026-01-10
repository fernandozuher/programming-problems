// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true
// C23

#include <stdio.h>

#define MAX_VALUE 99

void counter(int *frequency, int n);
int picking_numbers(const int *frequency);

int main()
{
    int n;
    scanf("%d", &n);
    int frequency[MAX_VALUE + 1] = {0}; // C23
    counter(frequency, n);
    printf("%d\n", picking_numbers(frequency));
    return 0;
}

void counter(int *frequency, int n)
{
    for (int i = 0, num; i < n; ++i) {
        scanf("%d", &num);
        ++frequency[num];
    }
}

// n: length of initial input array of numbers
// k: length of map frequency
// T:
//   With input values limited to 1 through 99, as stated in the problem:
//       Max of 99 keys/values allowed at array frequency: O(99) = O(1)
// S: O(1) extra space
int picking_numbers(const int *frequency)
{
    int max_len = 0;
    for (int i = 1, n2 = MAX_VALUE + 1; i < n2; ++i) {
        if (!frequency[i])
            continue;
        int current = frequency[i] + frequency[i + 1];
        max_len = max_len >= current ? max_len : current;
    }
    return max_len;
}
