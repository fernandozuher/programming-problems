// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<int> read_an_array(const int SIZE_ARRAY);
int jumping_on_clouds(const vector<int> ARRAY, const int JUMP_LENGTH);
int spent_energy_according_to_type_of_cloud(const int CLOUD_TYPE);
int generate_new_cloud_index(const int CLOUD_INDEX, const int SIZE_ARRAY, const int JUMP_LENGTH);
bool is_cloud_index_back_to_first_cloud(const int CLOUD_INDEX);


int main() {
    const int SIZE_ARRAY {read_a_number()};
    const int JUMP_LENGTH {read_a_number()};
    const vector<int> ARRAY {read_an_array(SIZE_ARRAY)};

    const int ENERGY {jumping_on_clouds(ARRAY, JUMP_LENGTH)};
    cout << ENERGY << "\n";

    return 0;
}

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    vector<int> read_an_array(const int SIZE_ARRAY) {
        vector<int> array(SIZE_ARRAY);
        generate(array.begin(), array.end(), []() {int element; cin >> element; return element;});
        return array;
    }

    int jumping_on_clouds(const vector<int> ARRAY, const int JUMP_LENGTH) {
        int energy {100};

        for (int cloud_index {0}; true; ) {
            energy -= spent_energy_according_to_type_of_cloud(ARRAY.at(cloud_index));
            cloud_index = {generate_new_cloud_index(cloud_index, ARRAY.size(), JUMP_LENGTH)};
            if (is_cloud_index_back_to_first_cloud(cloud_index))
                break;
        }

        return energy;
    }

        int spent_energy_according_to_type_of_cloud(const int CLOUD_TYPE) {
            return CLOUD_TYPE == 0 ? 1 : 3;
        }

        int generate_new_cloud_index(const int CLOUD_INDEX, const int SIZE_ARRAY, const int JUMP_LENGTH) {
            return (CLOUD_INDEX + JUMP_LENGTH) % SIZE_ARRAY;
        }

        bool is_cloud_index_back_to_first_cloud(const int CLOUD_INDEX) {
            return CLOUD_INDEX == 0;
        }
