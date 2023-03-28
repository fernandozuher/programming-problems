#include "Sequence_Equation.h"

Sequence_Equation::Sequence_Equation(const vector<int> array) {
    _input_array = {array};
    _elements_positions_array = {_generate_elements_positions_array()};
    _permutated_array = {_generate_permutated_array()};
}

    vector<int> Sequence_Equation::_generate_elements_positions_array() const {
        vector<int> elements_positions_array(_input_array.size());
        for (int i {0}, size {static_cast<int>(_input_array.size())}; i < size; i++)
            elements_positions_array[_input_array[i] - 1] = i;
        return elements_positions_array;
    }

    vector<int> Sequence_Equation::_generate_permutated_array() const {
        vector<int> permutated_array(_elements_positions_array.size());
        for (int i {0}, size {static_cast<int>(_elements_positions_array.size())}; i < size; i++)
            permutated_array[i] = {_elements_positions_array[_elements_positions_array[i]] + 1};
        return permutated_array;
    }

void Sequence_Equation::print_permutated_array() const {
    ranges::for_each(_permutated_array, [](auto element) {cout << element << "\n";});
}
