// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<int> read_an_array(const int SIZE_ARRAY);

class Jumping_On_The_Clouds {
private:
    vector<int> _array;
    int _jump_length;
    int _energy;

    void _jump_on_clouds() {
        for (int cloud_index {0}; true; ) {
            _energy -= _spent_energy_according_to_type_of_cloud(_array.at(cloud_index));
            cloud_index = {_generate_new_cloud_index(cloud_index)};
            if (_is_cloud_index_back_to_first_cloud(cloud_index))
                break;
        }
    }

        int _spent_energy_according_to_type_of_cloud(const int CLOUD_TYPE) const {
            return CLOUD_TYPE == 0 ? 1 : 3;
        }

        int _generate_new_cloud_index(const int CLOUD_INDEX) const {
            return (CLOUD_INDEX + _jump_length) % _array.size();
        }

        bool _is_cloud_index_back_to_first_cloud(const int CLOUD_INDEX) const {
            return CLOUD_INDEX == 0;
        }

public:
    Jumping_On_The_Clouds(const vector<int> ARRAY, const int JUMP_LENGTH) {
        _array = {ARRAY};
        _jump_length = {JUMP_LENGTH};
        _energy = {100};

        _jump_on_clouds();
    }

    int get_remaining_energy() const {
        return _energy;
    }
};


int main() {
    const int SIZE_ARRAY {read_a_number()};
    const int JUMP_LENGTH {read_a_number()};
    const vector<int> ARRAY {read_an_array(SIZE_ARRAY)};

    const Jumping_On_The_Clouds OBJ(ARRAY, JUMP_LENGTH);
    cout << OBJ.get_remaining_energy() << "\n";

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
