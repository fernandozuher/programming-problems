# Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

def solution(end_position, array):

    visited_positions = [False] * (end_position + 1)
    visited_positions_counter = 0
    i = 0

    while i < len(array) and visited_positions_counter < end_position:
        POSITION = array[i]
        HAS_THAT_POSITION_BEEN_VISITED = visited_positions[POSITION]

        if not HAS_THAT_POSITION_BEEN_VISITED:
            visited_positions[POSITION] = True
            visited_positions_counter += 1

        i += 1

    TIME_SPENT_JUMPING_ON_LEAFS = i - 1
    return TIME_SPENT_JUMPING_ON_LEAFS if visited_positions_counter == end_position else -1
