// Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

#include <stdbool.h>

int solution(const int end_position, const int* array, const int size)
{
    bool* visited_positions = (bool*) calloc(end_position + 1, sizeof(bool));
    int visited_positions_counter = 0;
    int i;

    for (i = 0; i < size && visited_positions_counter < end_position; ++i) {
        const int position = array[i];
        const bool has_that_position_been_visited = visited_positions[position];

        if (!has_that_position_been_visited) {
            visited_positions[position] = true;
            visited_positions_counter++;
        }
    }

    free(visited_positions);
    visited_positions = NULL;

    const int time_spent_jumping_on_leafs = i - 1;
    return visited_positions_counter == end_position ? time_spent_jumping_on_leafs : -1;
}
