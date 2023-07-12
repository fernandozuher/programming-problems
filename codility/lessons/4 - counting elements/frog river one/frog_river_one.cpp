// Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

int solution(const int end_position, vector<int>& array)
{
    vector<bool> visited_positions(end_position + 1);
    int visited_positions_counter {0};
    size_t i;

    for (i = {0}; i < array.size() && visited_positions_counter < end_position; ++i) {
        const int position {array.at(i)};
        const bool has_that_position_been_visited {visited_positions.at(position)};

        if (!has_that_position_been_visited) {
            visited_positions.at(position) = {true};
            visited_positions_counter++;
        }
    }

    const size_t time_spent_jumping_on_leafs {i - 1};
    return visited_positions_counter == end_position ? time_spent_jumping_on_leafs : -1;
}
