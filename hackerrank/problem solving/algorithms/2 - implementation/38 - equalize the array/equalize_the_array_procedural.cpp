// Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<int> read_an_array(const int SIZE);
int equalize_array(vector<int> array);
    int find_maximum_quantity_of_equal_element(const vector<int> ARRAY);
        bool are_consecutive_elementes_equal(const int ELEMENT_1, const int ELEMENT_2);


int main() {
    const int SIZE_ARRAY {read_a_number()};
    vector<int> array {read_an_array(SIZE_ARRAY)};

    const int MINIMUM_NUMBER_OF_DELETIONS_REQUIRED {equalize_array(array)};
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

    int equalize_array(vector<int> array) {
        ranges::sort(array);
        const int MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT {find_maximum_quantity_of_equal_element(array)};
        const int MINIMUM_NUMBER_OF_DELETIONS_REQUIRED {static_cast<int>(array.size()) - MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT};
        return MINIMUM_NUMBER_OF_DELETIONS_REQUIRED;
    }

        int find_maximum_quantity_of_equal_element(const vector<int> ARRAY) {
            int maximum_quantity_of_equal_element {1};

            for (int i {1}, temporary_quantity_equal_element {1}, SIZE {static_cast<int>(ARRAY.size())}; i < SIZE; i++) {
                if (are_consecutive_elementes_equal(ARRAY.at(i - 1), ARRAY.at(i))) {
                    temporary_quantity_equal_element++;
                    maximum_quantity_of_equal_element = {max(temporary_quantity_equal_element, maximum_quantity_of_equal_element)};
                }
                else
                    temporary_quantity_equal_element = {1};
            }

            return maximum_quantity_of_equal_element;
        }

            bool are_consecutive_elementes_equal(const int ELEMENT_1, const int ELEMENT_2) {
                return ELEMENT_1 == ELEMENT_2;
            }
