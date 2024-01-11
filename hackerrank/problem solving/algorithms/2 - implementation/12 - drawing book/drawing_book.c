// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int page_count(const int page_quantity, const int page);
    int calculate_turn_of_pages(const int page);
        int page_is_odd(const int page);
        int page_is_even(const int page);
    int get_minimum_turn_of_pages(const int turn_of_pages_from_front, const int turn_of_pages_from_back);

int main()
{
    int page_quantity, page;
    scanf("%d %d", &page_quantity, &page);
    printf("%d\n", page_count(page_quantity, page));

    return 0;
}

    int page_count(const int page_quantity, const int page)
    {
        int turn_of_pages_from_front = calculate_turn_of_pages(page);
        int maximum_turns = calculate_turn_of_pages(page_quantity);
        int turn_of_pages_from_back = maximum_turns - turn_of_pages_from_front;
        return get_minimum_turn_of_pages(turn_of_pages_from_front, turn_of_pages_from_back);
    }

        int calculate_turn_of_pages(const int page)
        {
            return page & 1 ? page_is_odd(page) : page_is_even(page);
        }

            int page_is_odd(const int page)
            {
                return (page - 1) / 2;
            }

            int page_is_even(const int page)
            {
                return page / 2;
            }

        int get_minimum_turn_of_pages(const int turn_of_pages_from_front, const int turn_of_pages_from_back)
        {
            return turn_of_pages_from_front < turn_of_pages_from_back ? turn_of_pages_from_front : turn_of_pages_from_back;
        }
