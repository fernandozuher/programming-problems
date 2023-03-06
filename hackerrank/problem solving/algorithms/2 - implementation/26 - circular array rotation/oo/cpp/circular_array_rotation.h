#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Circular_Array_Rotation {

private:
    vector<int> _array;
    int _array_size;
    int _rotation_count;
    vector<int> _queries;
    int _queries_size;

    void _reduce_input_rotations();
    void _rotate_array();
    void _print_rotated_array_elements_according_to_queries() const;

public:
    Circular_Array_Rotation(vector<vector<int>> input);
};
