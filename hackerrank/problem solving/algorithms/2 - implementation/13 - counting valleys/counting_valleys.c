// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* read_char_array(const int n);
int counting_valleys(const char* const steps, const int n);
    bool is_in_sea_level_from_valley(const bool was_travessing_a_valley, const int current_altitude);

int main()
{
    int n;
    scanf("%d", &n);
    char *array = read_char_array(n);
    printf("%d\n", counting_valleys(array, n));

    free(array);
    array = NULL;

    return 0;
}

    char* read_char_array(const int n)
    {
        char *array = (char*) calloc(n + 1, sizeof(char));
        scanf("%s", array);
        return array;
    }

    int counting_valleys(const char* const steps, const int n)
    {
        int traversed_valleys = 0;

        for (int i = 0, current_altitude = 0; i < n; ++i) {
            bool was_travessing_a_valley = current_altitude < 0;
            current_altitude += steps[i] == 'D' ? -1 : 1;

            if (is_in_sea_level_from_valley(was_travessing_a_valley, current_altitude))
                ++traversed_valleys;
        }

        return traversed_valleys;
    }

        bool is_in_sea_level_from_valley(const bool was_travessing_a_valley, const int current_altitude)
        {
            return was_travessing_a_valley && !current_altitude;
        }
