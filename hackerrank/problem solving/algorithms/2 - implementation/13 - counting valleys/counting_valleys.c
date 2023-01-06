// Source: https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* read_line_as_int_array(const int n);
char* read_line_as_char_array(const int n);
int counting_valleys(const char *steps, const int n);
    bool is_in_sea_level_from_valley(const bool was_travessing_a_valley, const int current_altitude);


int main() {
    const int *array_size = read_line_as_int_array(1);
    const int n = array_size[0];
    const char *steps = read_line_as_char_array(n);

    const int result = counting_valleys(steps, n);
    printf("%d\n", result);

    return 0;
}

    int* read_line_as_int_array(const int n) {
        int *input_line = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &input_line[i]);
        return input_line;
    }

    char* read_line_as_char_array(const int n) {
        char *input_line = (char*) calloc(n, sizeof(char));
        for (int i = 0; i < n; i++)
            scanf(" %c", &input_line[i]);
        return input_line;
    }

    int counting_valleys(const char *steps, const int n) {
        int traversed_valleys = 0;
        
        for (int i = 0, current_altitude = 0; i < n; i++) {
            bool was_travessing_a_valley = current_altitude < 0;
            current_altitude += steps[i] == 'D' ? -1 : 1;
            
            if (is_in_sea_level_from_valley(was_travessing_a_valley, current_altitude))
                traversed_valleys++;
        }

        return traversed_valleys;
    }

        bool is_in_sea_level_from_valley(const bool was_travessing_a_valley, const int current_altitude) {
            return was_travessing_a_valley && !current_altitude;
        }
