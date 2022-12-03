#include <stdio.h>
#include <stdlib.h> //calloc(), exit(), qsort()
#include <string.h> //strlen(), strcpy()

int compare_reverse (const void * a, const void * b) {
	return (*(int*)b - * (int*)a);
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

void choose_x(int *total_score, char opponent_choice) {
	total_score[0] += 1;
	if (opponent_choice == 'A') {
		total_score[0] += 3;
		total_score[1] += 3;
	}
	else if (opponent_choice == 'B')
		total_score[1] += 1;
	else {
		total_score[0] += 6;
		total_score[1] += 2;
	}
}

void choose_y(int *total_score, char opponent_choice) {
	total_score[0] += 2;
	total_score[1] += 3;
	if (opponent_choice == 'A') {
		total_score[0] += 6;
		total_score[1] += 1;
	}
	else if (opponent_choice == 'B') {
		total_score[0] += 3;
		total_score[1] += 2;
	}
	else
		total_score[1] += 3;
}

void choose_z(int *total_score, char opponent_choice) {
	total_score[0] += 3;
	total_score[1] += 6;
	if (opponent_choice == 'A')
		total_score[1] += 2;
	else if (opponent_choice == 'B') {
		total_score[0] += 6;
		total_score[1] += 3;
	}
	else {
		total_score[0] += 3;
		total_score[1] += 1;
	}
}

void calculate_total_score(char **input, int n) {
	// A, X = Rock; B, Y = Paper; C, Z = Scissor

	int total_score[] = {0, 0};
	for (int i = 0; i < n; i++) {
		char opponent_choice = input[i][0], my_choice = input[i][2];

		if (my_choice == 'X')
			choose_x(total_score, opponent_choice);
		else if (my_choice == 'Y')
			choose_y(total_score, opponent_choice);
		else
			choose_z(total_score, opponent_choice);
	}

	printf("total_score[0]: %d\ntotal_score[1]: %d\n", total_score[0], total_score[1]);
}

int main() {
	int input_lines = 2501;
	int expected_max_input_size = 5;
	int input_data_n = 0;

	char **input = read_input_from_file(input_lines, &input_data_n, expected_max_input_size);
	calculate_total_score(input, input_data_n);

	return 0;
}
