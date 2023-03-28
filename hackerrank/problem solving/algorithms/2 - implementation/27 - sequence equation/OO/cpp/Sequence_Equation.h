#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sequence_Equation {

private:
    vector<int> _input_array;
    vector<int> _elements_positions_array;
    vector<int> _permutated_array;

    vector<int> _generate_elements_positions_array() const;
    vector<int> _generate_permutated_array() const;

public:
    Sequence_Equation(const vector<int> array);

    void print_permutated_array() const;
};
