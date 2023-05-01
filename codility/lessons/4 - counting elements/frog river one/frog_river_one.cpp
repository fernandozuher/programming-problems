// Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

int solution(const int END_POSITION, vector<int>& array) {
    const int ARRAY_SIZE {static_cast<int>(array.size())};

    if (END_POSITION > ARRAY_SIZE)
        return -1;

    vector<bool> visited_positions(END_POSITION + 1);
    int visited_positions_counter {0};
    int i;

    for (i = {0}; i < ARRAY_SIZE && visited_positions_counter < END_POSITION; i++) {
        const int POSITION {array.at(i)};
        const bool HAS_THAT_POSITION_BEEN_VISITED {visited_positions.at(POSITION)};

        if (!HAS_THAT_POSITION_BEEN_VISITED) {
            visited_positions.at(POSITION) = {true};
            visited_positions_counter++;
        }
    }

    const int TIME_SPENT_JUMPING_ON_LEAFS {i - 1};

    return visited_positions_counter == END_POSITION ? TIME_SPENT_JUMPING_ON_LEAFS : -1;
}
