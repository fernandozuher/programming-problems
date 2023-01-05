// Source: https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_line_as_int_array(const int n);
int drawing_book(const int page_quantity, const int page);
    int calculate_turn_of_pages(const int page);
        int page_is_odd(const int page);
        int page_is_even(const int page);
    int get_minimum_turn_of_pages(const int turn_of_pages_from_front, const int turn_of_pages_from_back);


int main() {
    const int *page_quantity = read_line_as_int_array(1);
    const int *page = read_line_as_int_array(1);

    const int result = drawing_book(page_quantity[0], page[0]);
    printf("%d\n", result);

    return 0;
}

    int* read_line_as_int_array(const int n) {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &array[i]);
        return array;
    }

    int drawing_book(const int page_quantity, const int page) {
        const int turn_of_pages_from_front = calculate_turn_of_pages(page);
        
        const int maximum_turns = calculate_turn_of_pages(page_quantity);

        const int turn_of_pages_from_back = maximum_turns - turn_of_pages_from_front;

        return get_minimum_turn_of_pages(turn_of_pages_from_front, turn_of_pages_from_back);
    }

        int calculate_turn_of_pages(const int page) {
            return page & 1 ? page_is_odd(page) : page_is_even(page);
        }

            int page_is_odd(const int page) {
                return (page - 1) / 2;
            }

            int page_is_even(const int page) {
                return page / 2;
            }

        int get_minimum_turn_of_pages(const int turn_of_pages_from_front, const int turn_of_pages_from_back) {
            return turn_of_pages_from_front < turn_of_pages_from_back ? turn_of_pages_from_front : turn_of_pages_from_back;
        }
