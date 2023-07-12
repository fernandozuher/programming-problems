# Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

def solution(end_position, array)
    visited_positions = Array.new(end_position + 1)
    visited_positions_counter = 0
    i = 0

    while i < array.size && visited_positions_counter < end_position
        position = array[i]
        has_that_position_been_visited = visited_positions[position]

        if not has_that_position_been_visited
            visited_positions[position] = true
            visited_positions_counter += 1
        end

        i += 1
    end

    time_spent_jumping_on_leafs = i - 1
    visited_positions_counter == end_position ? time_spent_jumping_on_leafs : -1
end
