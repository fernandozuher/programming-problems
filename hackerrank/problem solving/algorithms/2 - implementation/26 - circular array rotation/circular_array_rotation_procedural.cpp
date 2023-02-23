// Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

#include <iostream>
#include <vector>

vector<vector<int>> read_input();
    vector<int> read_a_number();
    vector<int> read_array(const int SIZE);

vector<vector<int>> reduce_input_rotations(vector<vector<int>> input);
vector<vector<int>> rotate_input_array(vector<vector<int>> input);
void print_rotated_array_elements_according_to_queries(vector<vector<int>> input);


int main() {
    vector<vector<int>> input = read_input();

    input = reduce_input_rotations(input);
    input = rotate_input_array(input);
    print_rotated_array_elements_according_to_queries(input);

    return 0;
}

    vector<vector<int>> read_input() {
        vector<int> array_size {read_a_number()};
        vector<int> rotation_count {read_a_number()};
        vector<int> queries_size {read_a_number()};

        vector<int> array {read_array(array_size.front())};
        vector<int> queries {read_array(queries_size.front())};

        vector<vector<int>> input(5);
        input.at(0) = {array};
        input.at(1) = {array_size};
        input.at(2) = {rotation_count};
        input.at(3) = {queries};
        input.at(4) = {queries_size};

        return input;
    }

        vector<int> read_a_number() {
            vector<int> number(1);
            cin >> number.at(0);
            return number;
        }

        vector<int> read_array(const int SIZE) {
            vector<int> array(SIZE);
            for (int &element : array)
                *element = {read_a_number().front()};
            return array;
        }

    vector<vector<int>> reduce_input_rotations(vector<vector<int>> input) {
        const int ARRAY_SIZE {input.at(1).front()};
        int ROTATION_COUNT {input.at(2).front()};

        if (ARRAY_SIZE > 1)
            input.at(2).front() = ROTATION_COUNT = ROTATION_COUNT >= ARRAY_SIZE ? ROTATION_COUNT % ARRAY_SIZE : ROTATION_COUNT;
        else
            input.at(2).front() = ROTATION_COUNT = 0;

        return input;
    }

    vector<vector<int>> rotate_input_array(vector<vector<int>> input) {
        const vector<vector<int>> ARRAY = input.front().front();
        const int ARRAY_SIZE = input.at(1).front();
        const int ROTATION_COUNT = input.at(2).front();
        vector<int> new_array(ARRAY_SIZE);

        //memcpy(new_array, &ARRAY[ARRAY_SIZE - ROTATION_COUNT], ROTATION_COUNT * sizeof(*ARRAY));
        //memcpy(new_array + ROTATION_COUNT, ARRAY, (ARRAY_SIZE - ROTATION_COUNT) * sizeof(*ARRAY));

        input.front() = {new_array};
        return input;
    }

    void print_rotated_array_elements_according_to_queries(vector<vector<int>> input) {
        const vector<int> ARRAY {input.front()};
        const vector<int> QUERIES {input.at(3)};
        const int QUERIES_SIZE {input.at(4).front()};

        ranges::for_each(QUERIES, [ARRAY](auto query){ cout << ARRAY.at(query); });
    }
