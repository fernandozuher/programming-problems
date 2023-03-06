#include "circular_array_rotation.h"

Circular_Array_Rotation::Circular_Array_Rotation(vector<vector<int>> input) {
    _array = {input.front()};
    _array_size = {input.at(1).front()};
    _rotation_count = {input.at(2).front()};
    _queries = {input.at(3)};
    _queries_size = {input.at(4).front()};

    _reduce_input_rotations();
    _rotate_array();
    _print_rotated_array_elements_according_to_queries();
}

    void Circular_Array_Rotation::_reduce_input_rotations() {
        if (_array_size > 1)
            _rotation_count = {_rotation_count >= _array_size ? _rotation_count % _array_size : _rotation_count};
        else
            _rotation_count = {0};
    }

    void Circular_Array_Rotation::_rotate_array() {
        const auto FIRST_PART_ARRAY_BEGIN_ITERATOR = _array.begin();
        const auto FIRST_PART_ARRAY_END_ITERATOR = _array.begin() + _array_size - _rotation_count;

        const auto SECOND_PART_ARRAY_BEGIN_ITERATOR = _array.begin() + _array_size - _rotation_count;
        const auto SECOND_PART_ARRAY_END_ITERATOR = _array.end();

        vector<int> new_array {SECOND_PART_ARRAY_BEGIN_ITERATOR, SECOND_PART_ARRAY_END_ITERATOR};
        const vector<int> SECOND_PART_NEW_ARRAY {FIRST_PART_ARRAY_BEGIN_ITERATOR, FIRST_PART_ARRAY_END_ITERATOR};
        new_array.insert(new_array.end(), SECOND_PART_NEW_ARRAY.begin(), SECOND_PART_NEW_ARRAY.end());

        _array = {new_array};
    }

    void Circular_Array_Rotation::_print_rotated_array_elements_according_to_queries() const {
        auto print = [&](const auto & query) {cout << _array.at(query) << "\n";};
        ranges::for_each(_queries, print);
    }
