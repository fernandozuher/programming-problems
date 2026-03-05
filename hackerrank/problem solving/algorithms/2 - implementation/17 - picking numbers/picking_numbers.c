// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true
// C23

#include <stdio.h>

#define MAX_VALUE 99

void counter(int *freq_map, int n);
int picking_numbers(const int *freq_map);

int main()
{
    int n;
    scanf("%d", &n);
    int freq_map[MAX_VALUE + 1] = {};
    counter(freq_map, n);
    printf("%d\n", picking_numbers(freq_map));
    return 0;
}

// n: length of initial input array of numbers
// k: length of freq_map
// k <= n
// T: O(n)
// S: O(k) = O(n) extra space
void counter(int *freq_map, int n)
{
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        ++freq_map[num];
    }
}

// k: length of freq_map
// 1 <= k <= 99
// T: O(k) = O(99) = O(1)
// S: O(1) extra space
int picking_numbers(const int *freq_map)
{
    int max_len = 0;
    for (int i = 1, n2 = MAX_VALUE + 1; i < n2; ++i) {
        if (!freq_map[i])
            continue;
        int current = freq_map[i] + freq_map[i + 1];
        max_len = max_len >= current ? max_len : current;
    }
    return max_len;
}
