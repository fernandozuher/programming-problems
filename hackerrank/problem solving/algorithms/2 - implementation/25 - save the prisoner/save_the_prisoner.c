// Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

#include <stdio.h>

int read_a_number();

int* read_test_cases_and_save_the_prisoners(const int N_TEST_CASES);
    int* read_test_case();
    int save_the_prisoner(int* test_case);

void print_results(const int *ARRAY, const int SIZE);
int* free_array(int *array);


int main() {
    const int N_TEST_CASES = read_a_number();
    int *prisoners_chair_number_to_warn = read_test_cases_and_save_the_prisoners(N_TEST_CASES);
    print_results(prisoners_chair_number_to_warn, N_TEST_CASES);

    prisoners_chair_number_to_warn = free_array(prisoners_chair_number_to_warn);
    return 0;
}

    int read_a_number() {
        int number;
        scanf("%d", &number);
        return number;
    }

    int* read_test_cases_and_save_the_prisoners(const int N_TEST_CASES) {
        int *prisoners_chair_number_to_warn = (int*) calloc (N_TEST_CASES, sizeof(int));

        for (int i = 0; i < N_TEST_CASES; i++) {
            int *test_case = read_test_case();
            prisoners_chair_number_to_warn[i] = save_the_prisoner(test_case);
            test_case = free_array(test_case);
        }

        return prisoners_chair_number_to_warn;
    }

        int* read_test_case() {
            const int TEST_CASE_SIZE = 3;
            int *test_case = (int*) calloc(TEST_CASE_SIZE, sizeof(int));
            scanf("%d %d %d", &test_case[0], &test_case[1], &test_case[2]);
            return test_case;
        }

        int save_the_prisoner(int* test_case) {
            const int PRISONERS = test_case[0];
            const int SWEETS = test_case[1];
            const int CHAIR_NUMBER_TO_BEGIN = test_case[2];
            int prisoner_chair_number_to_warn = CHAIR_NUMBER_TO_BEGIN + (SWEETS - 1);

            if (prisoner_chair_number_to_warn > PRISONERS) {
                prisoner_chair_number_to_warn %= PRISONERS;

                if (prisoner_chair_number_to_warn == 0)
                    prisoner_chair_number_to_warn = PRISONERS;
            }

            return prisoner_chair_number_to_warn;
        }

    void print_results(const int *ARRAY, const int SIZE) {
        for (int i = 0; i < SIZE; i++)
            printf("%d\n", ARRAY[i]);
    }

    int* free_array(int *array) {
        free(array);
        return NULL;
    }
