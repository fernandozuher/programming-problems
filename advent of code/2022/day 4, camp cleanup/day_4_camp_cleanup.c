#include <stdio.h>
#include <stdlib.h> //calloc(), exit(), qsort()
#include <string.h> //strlen(), strcpy(), strncpy(), strtok()
#include <stdbool.h>

void camp_cleanup(char **input, int n);
    int** find_ranges(char *line);
    int* is_range_inside_another_range(int **elves_ranges);


char** read_input_from_file(int input_lines, int *n, int expected_max_input_size) {
    FILE *fp = fopen("input.txt", "r");

    if (!fp) {
        printf("\nError in opening file.\n");
        exit(EXIT_FAILURE);
    }

    int max_size = expected_max_input_size;
    char **input = (char**) calloc(input_lines, sizeof(char*));

    for (char temp_string[max_size]; fgets(temp_string, max_size, fp); (*n)++) {
        input[*n] = (char*) calloc(max_size, sizeof(char));
        strcpy(input[*n], temp_string);
    }

    fclose(fp);
    return input;
}

void camp_cleanup(char **input, int n) {
    int ranges_inside_another = 0;
    int ranges_overlap_at_all = 0;

    for (int i = 0; i < n; i++) {
        int **elves_ranges = find_ranges(input[i]);
        int *output = is_range_inside_another_range(elves_ranges);
        ranges_inside_another += output[0];
        ranges_overlap_at_all += output[1];
input    }
    printf("%d\n%d\n", ranges_inside_another, ranges_overlap_at_all);
}

    int** find_ranges(char *line) {
        int *elf1 = (int*) calloc(2, sizeof(int));
        int *elf2 = (int*) calloc(2, sizeof(int));

        elf1[0] = atoi(strtok(line, "-"));
        elf1[1] = atoi(strtok(NULL, ","));

        elf2[0] = atoi(strtok(NULL, "-"));
        elf2[1] = atoi(strtok(NULL, ""));

        int **elves_ranges = (int**) calloc(2, sizeof(int*));
        elves_ranges[0] = elf1;
        elves_ranges[1] = elf2;

        return elves_ranges;
    }

    int* is_range_inside_another_range(int **elves_ranges) {
        int elf1_init = elves_ranges[0][0];
        int elf1_end = elves_ranges[0][1];

        int elf2_init = elves_ranges[1][0];
        int elf2_end = elves_ranges[1][1];

        int* output = (int*) calloc(2, sizeof(int));
        bool logic1 = (elf1_init >= elf2_init && elf1_init <= elf2_end);
        bool logic2 = (elf1_end >= elf2_init && elf1_end <= elf2_end);
        bool logic3 = (elf2_init >= elf1_init && elf2_init <= elf1_end);
        bool logic4 = (elf2_end >= elf1_init && elf2_end <= elf1_end);

        if ((logic1 && logic2) || (logic3 && logic4))
            output[0] = 1;
    
        if ((logic1 || logic2) || (logic3 || logic4))
            output[1] = 1;
        
        return output;
    }

int main() {
    int input_lines = 1000;
    int expected_max_input_size = 13;
    int input_data_n = 0;

    char **input = read_input_from_file(input_lines, &input_data_n, expected_max_input_size);
    camp_cleanup(input, input_data_n);
    return 0;
}
