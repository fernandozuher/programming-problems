#include <stdio.h>
#include <stdlib.h> //calloc(), exit(), qsort()
#include <string.h> //strlen(), strcpy(), strncpy()

void find_common_item_types(char **input, int n);

int common_item_in_ruckstack(char *line);
	char** get_two_string_halves(const char *line);
	char* deduplicate_string(char *string);
	int find_common_item_in_ruckstack(const char *first_half_items, const char *second_half_items);
		int convert_item_to_value(const char item);

int common_item_in_group(const int index, char **last_3_rucksacks);
	void put_smallest_array_first(char **input_array);
	int find_common_item_in_group(char **last_3_rucksacks);


int compare (const void * a, const void * b) {
	return (*(int*)a - * (int*)b);
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

void find_common_item_types(char **input, int n) {

	int sum = 0, sum2 = 0;
	for (int i = 0, index_item_in_group = 2; i < n; i++, index_item_in_group += 3) {

		sum += common_item_in_ruckstack(input[i]);

		{
			int i = index_item_in_group;
			if (i < n) {
				//char **last_3_rucksacks = (char**) calloc(3, sizeof(char*));
				char *last_3_rucksacks[3] = {input[i - 2], input[i - 1], input[i]};
				sum2 += common_item_in_group(i, last_3_rucksacks);
			}
		}

	}
	printf("sum: %d\nsum2: %d", sum, sum2);
}

	int common_item_in_ruckstack(char *line) {
		char **halves = get_two_string_halves(line);

		char *deduplicated_halve1 = deduplicate_string(halves[0]);
		char *deduplicated_halve2 = deduplicate_string(halves[1]);

		free(halves[0]);
		free(halves[1]);
		free(halves);

		int common_item_value = find_common_item_in_ruckstack(deduplicated_halve1, deduplicated_halve2);

		free(deduplicated_halve1);
		free(deduplicated_halve2);

		return common_item_value;
	}

		char** get_two_string_halves(const char *line) {
			int n2 = strlen(line) / 2;
			char *first_half_items = (char*) calloc(n2 + 1, sizeof(char));
			char *second_half_items = (char*) calloc(n2 + 1, sizeof(char));

			strncpy(first_half_items, line, n2);
			strncpy(second_half_items, line + n2, n2);
			first_half_items[n2] = '\0';
			second_half_items[n2] = '\0';

			char **two_halves = (char**) calloc(2, sizeof(char*));
			two_halves[0] = first_half_items;
			two_halves[1] = second_half_items;

			return two_halves;
		}

		char* deduplicate_string(char *string) {
			int n = strlen(string);
			qsort(string, n, sizeof(char), compare);

			char *deduplicated_string = (char*) calloc(n, sizeof(char));
			deduplicated_string[0] = string[0];
			int n_deduplicated = 1;

			for (int j = 1; j < n; j++)
				if (string[j] != string[j - 1])
					deduplicated_string[n_deduplicated++] = string[j];

			return deduplicated_string;
		}

		int find_common_item_in_ruckstack(const char *first_half_items, const char *second_half_items) {
			int common_item_value = 0;
			int n_first = strlen(first_half_items);
			int n_second = strlen(second_half_items);

			for (int j = 0; j < n_first; j++)
				for (int k = 0; k < n_second; k++)
					if (first_half_items[j] == second_half_items[k]) {
						common_item_value = convert_item_to_value(first_half_items[j]);
						j = n_first;
						break;
					}

			return common_item_value;
		}

			int convert_item_to_value(const char item) {
				return (item >= 65 && item <= 90) ? item - 'A' + 27 : item - 'a' + 1;
			}

	int common_item_in_group(const int index, char **last_3_rucksacks) {
		put_smallest_array_first(last_3_rucksacks);
		int common_item_value = find_common_item_in_group(last_3_rucksacks);
		return common_item_value;
	}

		void put_smallest_array_first(char **input_array) {
			char *smallest_rucksack = input_array[0];
			char *smallest_rucksack2 = input_array[1];
			char *smallest_rucksack3 = input_array[2];

			if (strlen(smallest_rucksack) <= strlen(smallest_rucksack2) && strlen(smallest_rucksack) <= strlen(smallest_rucksack3)) {

			}
			else if (strlen(smallest_rucksack2) <= strlen(smallest_rucksack) && strlen(smallest_rucksack2) <= strlen(smallest_rucksack3)) {
				char *temp = smallest_rucksack;
				input_array[0] = smallest_rucksack2;
				input_array[1] = temp;
			}
			else if (strlen(smallest_rucksack3) <= strlen(smallest_rucksack) && strlen(smallest_rucksack3) <= strlen(smallest_rucksack2)) {
				char *temp = smallest_rucksack;
				input_array[0] = smallest_rucksack3;
				input_array[2] = temp;
			}
		}

		int find_common_item_in_group(char **last_3_rucksacks) {
			const char *smallest_rucksack = last_3_rucksacks[0];
			const char *rucksack2 = last_3_rucksacks[1];
			const char *rucksack3 = last_3_rucksacks[2];

			int common_item_value = 0;
			for (int i = 0, n = strlen(smallest_rucksack); i < n; i++)
				for (int j = 0, n2 = strlen(rucksack2); j < n2; j++)

					if (smallest_rucksack[i] == rucksack2[j])
						for (int k = 0, n3 = strlen(rucksack3); k < n3; k++)
							if (smallest_rucksack[i] == rucksack3[k]) {
								common_item_value = convert_item_to_value(smallest_rucksack[i]);
								return common_item_value;
							}
		}

int main() {
	int input_lines = 300;
	int expected_max_input_size = 50;
	int input_data_n = 0;

	char **input = read_input_from_file(input_lines, &input_data_n, expected_max_input_size);
	find_common_item_types(input, input_data_n);

	return 0;
}
