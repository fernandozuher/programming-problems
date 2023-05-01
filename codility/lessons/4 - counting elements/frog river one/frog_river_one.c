// Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

#include <stdbool.h>

int solution(const int END_POSITION, const int* ARRAY, const int ARRAY_SIZE) {
    if (END_POSITION > ARRAY_SIZE)
        return -1;

    bool* visited_positions = (bool*) calloc(END_POSITION + 1, sizeof(bool));
    int visited_positions_counter = 0;
    int i;

    for (i = 0; i < ARRAY_SIZE && visited_positions_counter < END_POSITION; i++) {
        const int POSITION = ARRAY[i];
        const bool HAS_THAT_POSITION_BEEN_VISITED = visited_positions[POSITION];

        if (!HAS_THAT_POSITION_BEEN_VISITED) {
            visited_positions[ARRAY[i]] = true;
            visited_positions_counter++;
        }
    }

    const int TIME_SPENT_JUMPING_ON_LEAFS = i - 1;

    free(visited_positions);
    visited_positions = NULL;

    return visited_positions_counter == END_POSITION ? TIME_SPENT_JUMPING_ON_LEAFS : -1;
}
