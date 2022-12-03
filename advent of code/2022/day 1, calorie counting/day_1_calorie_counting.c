#include <stdio.h>
#include <stdlib.h> //calloc(), exit(), qsort()
#include <string.h> //strlen(), strcpy()

int compare_reverse (const void * a, const void * b) {
	return (*(int*)b - *(int*)a);
}

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

void find_most_calories(char **input, int n) {
	int calories_of_elves[n / 2]; // at maximum n(calories)/2 -> elves
	int n_elves = 0;

	for (int i = 0, counter = 0; i < n; i++)
		if (strcmp(input[i], "\n"))
			counter += atoi(input[i]);
		else {
			calories_of_elves[n_elves++] = counter;
			counter = 0;
		}

	qsort(calories_of_elves, n_elves, sizeof(int), compare_reverse);
	int max_sum = calories_of_elves[0];
	int sum_most_three_calories = calories_of_elves[0] + calories_of_elves[1] + calories_of_elves[2];

	printf("\nmax_calorie: %d\nsum_most_three_calories: %d\n", max_sum, sum_most_three_calories);
}

int main() {
	int input_lines = 2244;
	int expected_max_input_size = 7;
	int input_data_n = 0;

	char **input = read_input_from_file(input_lines, &input_data_n, expected_max_input_size);
	find_most_calories(input, input_data_n);

	return 0;
}
