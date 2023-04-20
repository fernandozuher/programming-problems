// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<int> read_an_array(const int SIZE);

class Jumping_On_The_Clouds {

private:
    vector<int> _cloud_array;
    int _minimum_number_of_jumps;

    void _calculate_minimum_number_of_jumps() {
        for (int i {0}, size {static_cast<int>(_cloud_array.size() - 1)}; i < size; ) {
            i = {_get_index_of_next_jump(i)};
            _minimum_number_of_jumps++;
        }
    }

        int _get_index_of_next_jump(int index) const {
            if (_is_next_second_index_inside_range(index + 2))
                index += _is_next_second_cloud_cumulus(_cloud_array.at(index + 2)) ? 2 : 1;
            else
                index++;
            return index;
        }

            bool _is_next_second_index_inside_range(const int INDEX) const {
                return INDEX < static_cast<int>(_cloud_array.size());
            }

            bool _is_next_second_cloud_cumulus(const int TYPE_OF_CLOUD) const {
                return TYPE_OF_CLOUD == 0;
            }

public:
    Jumping_On_The_Clouds(const vector<int> CLOUD_ARRAY) {
        _cloud_array = {CLOUD_ARRAY};
        _minimum_number_of_jumps = {0};

        _calculate_minimum_number_of_jumps();
    }

    int get_minimum_number_of_jumps() const {
        return _minimum_number_of_jumps;
    }
};

int main() {
    const int N_CLOUDS {read_a_number()};
    const vector<int> CLOUD_ARRAY {read_an_array(N_CLOUDS)};
    
    const Jumping_On_The_Clouds OBJ(CLOUD_ARRAY);
    const int MINIMUM_NUMBER_OF_JUMPS {OBJ.get_minimum_number_of_jumps()};
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
        generate(array.begin(), array.end(), []() {int element; cin >> element; return element;});
        return array;
    }
