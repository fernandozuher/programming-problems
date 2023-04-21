// Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int read_a_number();
int* read_an_array(const int SIZE);
int equalize_array(int* array, const int SIZE_ARRAY);
    void sort_array(int* array, const int SIZE_ARRAY);
        int compare_function(const void* A, const void* B);
    int find_maximum_quantity_of_equal_element(const int* ARRAY, const int SIZE_ARRAY);
        bool are_consecutive_elementes_equal(const int ELEMENT_1, const int ELEMENT_2);
int* free_array(int* array);


int main() {
    const int SIZE_ARRAY = read_a_number();
    int* array = read_an_array(SIZE_ARRAY);

    const int MINIMUM_NUMBER_OF_DELETIONS_REQUIRED  = equalize_array(array, SIZE_ARRAY);
    printf("%d\n", MINIMUM_NUMBER_OF_DELETIONS_REQUIRED);

    array = free_array(array);

    return 0;
}

    int read_a_number() {
        int number;
        scanf("%d", &number);
        return number;
    }

    int* read_an_array(const int SIZE) {
        int* array = (int*) calloc(SIZE, sizeof(int));
        for (int i = 0; i < SIZE; ++i)
            scanf("%d", &array[i]);
        return array;
    }

    int equalize_array(int* array, const int SIZE_ARRAY) {
        sort_array(array, SIZE_ARRAY);
        const int MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT = find_maximum_quantity_of_equal_element(array, SIZE_ARRAY);
        const int MINIMUM_NUMBER_OF_DELETIONS_REQUIRED = SIZE_ARRAY - MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT;
        return MINIMUM_NUMBER_OF_DELETIONS_REQUIRED;
    }

        void sort_array(int* array, const int SIZE_ARRAY) {
            qsort(array, SIZE_ARRAY, sizeof(int), compare_function);
        }

            int compare_function(const void* A, const void* B) {
                return (*(int*) A - * (int*) B);
            }

        int find_maximum_quantity_of_equal_element(const int* ARRAY, const int SIZE_ARRAY) {
            int maximum_quantity_of_equal_element = 1;

            for (int i = 1, temporary_quantity_equal_element = 1; i < SIZE_ARRAY; i++) {
                if (are_consecutive_elementes_equal(ARRAY[i - 1], ARRAY[i])) {
                    temporary_quantity_equal_element++;

                    if (temporary_quantity_equal_element > maximum_quantity_of_equal_element)
                        maximum_quantity_of_equal_element = temporary_quantity_equal_element;
                }
                else
                    temporary_quantity_equal_element = 1;
            }

            return maximum_quantity_of_equal_element;
        }

            bool are_consecutive_elementes_equal(const int ELEMENT_1, const int ELEMENT_2) {
                return ELEMENT_1 == ELEMENT_2;
            }

    int* free_array(int* array) {
        free(array);
        return NULL;
    }
