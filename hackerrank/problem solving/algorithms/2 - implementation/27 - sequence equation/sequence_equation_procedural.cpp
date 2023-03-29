// Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<int> read_an_array(const int SIZE);
vector<int> permutation_equation(const vector<int> ARRAY);
    vector<int> generate_elements_positions_array(const vector<int> ARRAY);
    vector<int> generate_permutated_array(const vector<int> ARRAY);
void print_array(const vector<int> ARRAY);


int main() {
    const int SIZE {read_a_number()};
    const vector<int> ARRAY {read_an_array(SIZE)};

    const vector<int> PERMUTATED_ARRAY {permutation_equation(ARRAY)};
    print_array(PERMUTATED_ARRAY);

    return 0;
}

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    vector<int> read_an_array(const int SIZE) {
        vector<int> array(SIZE);
        auto read = []() {int element; cin >> element; return element;};
        ranges::generate(array, read);
        return array;
    }

    vector<int> permutation_equation(const vector<int> ARRAY) {
        const vector<int> ELEMENTS_POSITIONS_ARRAY {generate_elements_positions_array(ARRAY)};
        const vector<int> PERMUTATED_ARRAY {generate_permutated_array(ELEMENTS_POSITIONS_ARRAY)};
        return PERMUTATED_ARRAY;
    }

        vector<int> generate_elements_positions_array(const vector<int> ARRAY) {
            vector<int> elements_positions_array(ARRAY.size());
            for (int i {0}, size {static_cast<int>(ARRAY.size())}; i < size; i++)
                elements_positions_array[ARRAY[i] - 1] = i;
            return elements_positions_array;
        }

        vector<int> generate_permutated_array(const vector<int> ARRAY) {
            vector<int> permutated_array(ARRAY.size());
            for (int i {0}, size {static_cast<int>(ARRAY.size())}; i < size; i++)
                permutated_array[i] = {ARRAY[ARRAY[i]] + 1};
            return permutated_array;
        }

    void print_array(const vector<int> ARRAY) {
        ranges::for_each(ARRAY, [](auto element) {cout << element << "\n";});
    }
