// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

#include <stdio.h>
#include <stdbool.h>

int minimum_number_of_jumps(const int* const clouds, const int n);
    int next_jump(const int index, const int* const clouds, const int n);

int main()
{
    int n;
    scanf("%d", &n);
    int clouds[n];
    for (int i = 0; i < n; scanf("%d", &clouds[i++]));
    printf("%d\n", minimum_number_of_jumps(clouds, n));

    return 0;
}

    int minimum_number_of_jumps(const int* const clouds, const int n)
    {
        int jumps = 0;
        for (int i = 0, size = n - 1; i < size; ++jumps)
            i += next_jump(i, clouds, n);
        return jumps;
    }

        int next_jump(const int index, const int* const clouds, const int n)
        {
            bool is_next_second_cloud_cumulus = false;
            if (index + 2 < n)
                is_next_second_cloud_cumulus = clouds[index + 2] == 0;
            return is_next_second_cloud_cumulus ? 2 : 1;
        }
