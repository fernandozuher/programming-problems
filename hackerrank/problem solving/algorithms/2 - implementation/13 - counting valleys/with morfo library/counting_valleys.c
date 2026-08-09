// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "morfo/io.h"

int counting_valleys(const char *steps, int n);

int main()
{
    morfo_skip_input_ln();
    char *steps = morfo_read(char *);
    printf("%d\n", counting_valleys(steps, (int)strlen(steps)));
    free(steps);
    return 0;
}

// n: length of steps
// T: O(n)
// S: O(1) extra space
int counting_valleys(const char *steps, int n)
{
    int valleys = 0;

    for (int i = 0, current_altitude = 0; i < n; ++i) {
        bool was_below_sea_level = current_altitude < 0;
        current_altitude += steps[i] == 'D' ? -1 : 1;
        bool is_in_sea_level_from_valley = was_below_sea_level && current_altitude == 0;
        valleys += is_in_sea_level_from_valley;
    }

    return valleys;
}
