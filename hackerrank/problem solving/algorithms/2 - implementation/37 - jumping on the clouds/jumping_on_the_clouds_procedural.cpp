// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<int> read_an_array(const int SIZE);
int calculate_minimum_number_of_jumps(const vector<int> ARRAY);
    int get_index_of_next_jump(int index, const vector<int> ARRAY);
        bool is_next_second_index_inside_range(const int INDEX, const int SIZE);
        bool is_next_second_cloud_cumulus(const int type_of_cloud);


int main() {
    const int N_CLOUDS {read_a_number()};
    const vector<int> CLOUD_ARRAY {read_an_array(N_CLOUDS)};
    const int MINIMUM_NUMBER_OF_JUMPS {calculate_minimum_number_of_jumps(CLOUD_ARRAY)};
    cout << MINIMUM_NUMBER_OF_JUMPS << "\n";

    return 0;
}

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    vector<int> read_an_array(const int SIZE) {
        vector<int> array(SIZE);
        generate(array.begin(), array.end(), [](){int element; cin >> element; return element;});
        return array;
    }

    int calculate_minimum_number_of_jumps(const vector<int> ARRAY) {
        int jumps {0};

        for (int i {0}, size {static_cast<int>(ARRAY.size() - 1)}; i < size; ) {
            i = get_index_of_next_jump(i, ARRAY);
            jumps++;
        }

        return jumps;
    }

        int get_index_of_next_jump(int index, const vector<int> ARRAY) {
            if (is_next_second_index_inside_range(index + 2, ARRAY.size()))
                index += is_next_second_cloud_cumulus(ARRAY.at(index + 2)) ? 2 : 1;
            else
                index++;
            return index;
        }

            bool is_next_second_index_inside_range(const int INDEX, const int SIZE) {
                return INDEX < SIZE;
            }

            bool is_next_second_cloud_cumulus(const int TYPE_OF_CLOUD) {
                return TYPE_OF_CLOUD == 0;
            }
