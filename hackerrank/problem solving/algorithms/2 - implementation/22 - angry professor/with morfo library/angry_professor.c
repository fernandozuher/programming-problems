// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/collections.h"
#include "morfo/io.h"

bool angry_professor(const int *arrival_times, int n, int threshold);

int main()
{
    int n = morfo_read(int);

    for (int i = 0; i < n; ++i) {
        morfo_skip_input();
        int threshold = morfo_read(int);
        size_t size;
        int *arrival_times = morfo_readln(int, &size);
        puts(angry_professor(arrival_times, (int)size, threshold) ? "YES" : "NO");
        free(arrival_times);
    }

    return 0;
}

static bool is_on_time(int t) { return t <= 0; }

// k: length of arrival_times
// T: O(k)
// S: O(1) extra space
bool angry_professor(const int *arrival_times, int n, int threshold)
{
    int on_time = (int) morfo_count_if(arrival_times, (size_t) n, is_on_time);
    return on_time < threshold;
}
