// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true
// C23

#include <stdio.h>

int counting_valleys(const char steps[], int n);

int main()
{
    int n;
    scanf("%d\n", &n);
    char steps[n + 1];
    fgets(steps, n + 1, stdin);
    printf("%d\n", counting_valleys(steps, n));
    return 0;
}

int counting_valleys(const char steps[], int n)
{
    int valleys = 0;

    for (int i = 0, current_altitude = 0; i < n; ++i) {
        bool was_below_sea_level = current_altitude < 0;
        current_altitude += steps[i] == 'D' ? -1 : 1;
        bool is_in_sea_level_from_valley = was_below_sea_level && current_altitude == 0;
        if (is_in_sea_level_from_valley)
            ++valleys;
    }

    return valleys;
}
