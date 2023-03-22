// Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<int> read_an_array(const int SIZE);
vector<int> permutation_equation(const vector<int> ARRAY);
    vector<int> generate_array_of_elements_positions(const vector<int> ARRAY);
    vector<int> generate_permutated_array(const vector<int> ARRAY);
void print_array(const vector<int> ARRAY);


int main() {
    const int SIZE = read_a_number();
    const vector<int> ARRAY = read_an_array(SIZE);

    const vector<int> PERMUTATED_ARRAY = permutation_equation(ARRAY);
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
        const vector<int> ARRAY_ELEMENTS_POSITIONS = generate_array_of_elements_positions(ARRAY);
        const vector<int> PERMUTATED_ARRAY = generate_permutated_array(ARRAY_ELEMENTS_POSITIONS);
        return PERMUTATED_ARRAY;
    }

        vector<int> generate_array_of_elements_positions(const vector<int> ARRAY) {
            vector<int> array_elements_positions(ARRAY.size());
            for (int i = 0, size = ARRAY.size(); i < size; i++)
                array_elements_positions[ARRAY[i] - 1] = i;
            return array_elements_positions;
        }

        vector<int> generate_permutated_array(const vector<int> ARRAY) {
            vector<int> permutated_array(ARRAY.size());
            for (int i = 0, size = ARRAY.size(); i < size; i++)
                permutated_array[i] = ARRAY[ARRAY[i]] + 1;
            return permutated_array;
        }

    void print_array(const vector<int> ARRAY) {
        ranges::for_each(ARRAY, [](auto element) {cout << element << "\n";});
    }
