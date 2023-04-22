// Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<int> read_an_array(const int SIZE);

class Equalize_The_Array {

private:
    vector<int> _array;
    int _minimum_number_of_deletions_required;

    void _equalize_array() {
        const int MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT {_find_maximum_quantity_of_equal_element()};
        _minimum_number_of_deletions_required = {static_cast<int>(_array.size()) - MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT};
    }

        int _find_maximum_quantity_of_equal_element() const {
            int maximum_quantity_of_equal_element {1};

            for (int i {1}, temporary_quantity_equal_element {1}, SIZE {static_cast<int>(_array.size())}; i < SIZE; i++) {
                if (_are_consecutive_elementes_equal(_array.at(i - 1), _array.at(i))) {
                    temporary_quantity_equal_element++;
                    maximum_quantity_of_equal_element = {max(temporary_quantity_equal_element, maximum_quantity_of_equal_element)};
                }
                else
                    temporary_quantity_equal_element = {1};
            }

            return maximum_quantity_of_equal_element;
        }

            bool _are_consecutive_elementes_equal(const int ELEMENT_1, const int ELEMENT_2) const {
                return ELEMENT_1 == ELEMENT_2;
            }

public:
    Equalize_The_Array(const vector<int> ARRAY) {
        _array = {ARRAY};
        ranges::sort(_array);
        _equalize_array();
    }

    int get_minimum_number_of_deletions_required() const {
        return _minimum_number_of_deletions_required;
    }
};

int main() {
    const int SIZE_ARRAY {read_a_number()};
    const vector<int> ARRAY {read_an_array(SIZE_ARRAY)};

    const Equalize_The_Array OBJ(ARRAY);
    const int MINIMUM_NUMBER_OF_DELETIONS_REQUIRED {OBJ.get_minimum_number_of_deletions_required()};
    cout << MINIMUM_NUMBER_OF_DELETIONS_REQUIRED << "\n";

    return 0;
}

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    vector<int> read_an_array(const int SIZE) {
        vector<int> array(SIZE);
        ranges::generate(array, []{int element; cin >> element; return element;});
        return array;
    }
