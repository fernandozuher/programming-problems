// Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

#include <iostream>

using namespace std;

string read_a_string();
int read_a_number();
void print_output(const bool RESPONSE);


class Append_And_Delete {

private:
    string _initial_string;
    string _final_string;
    int _number_of_operations;

    int _common_prefix_size_between_strings;
    bool _are_operations_suitable_to_replacement;

    void _append_and_delete() {
        _common_prefix_size_between_strings = {_find_common_prefix_size_between_strings()};

        const int SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING {static_cast<int>(_initial_string.length()) - _common_prefix_size_between_strings};
        const int SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING {static_cast<int>(_final_string.length()) - _common_prefix_size_between_strings};

        const int MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING {SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING + SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING};

        _number_of_operations -= MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING;
        _are_operations_suitable_to_replacement = {_are_operations_suitable_to_replace_string()};
    }

        int _find_common_prefix_size_between_strings() {
            int size {0};
            const int INITIAL_STRING_SIZE {static_cast<int>(_initial_string.length())};
            const int FINAL_STRING_SIZE {static_cast<int>(_final_string.length())};

            while (INITIAL_STRING_SIZE != size && FINAL_STRING_SIZE != size && _initial_string.at(size) == _final_string.at(size))
                size++;
            return size;
        }

        bool _are_operations_suitable_to_replace_string() {
            if (_number_of_operations < 0 ||
                    (_are_operations_bigger_than_zero_and_odd() && _are_not_operations_enough_to_remove_and_replace_common_prefix()))
                return false;
            return true;
        }

            bool _are_operations_bigger_than_zero_and_odd() {
                return _number_of_operations > 0 && _number_of_operations % 2 == 1;
            }

            bool _are_not_operations_enough_to_remove_and_replace_common_prefix() {
                return _number_of_operations < _common_prefix_size_between_strings * 2;
            }

public:
    Append_And_Delete(const string INITIAL_STRING, const string FINAL_STRING, const int NUMBER_OF_OPERATIONS) {
        _initial_string = {INITIAL_STRING};
        _final_string = {FINAL_STRING};
        _number_of_operations = {NUMBER_OF_OPERATIONS};

        _append_and_delete();
    }

    bool get_response() const {
        return _are_operations_suitable_to_replacement;
    }
};

int main() {
    const string INITIAL_STRING {read_a_string()};
    const string FINAL_STRING {read_a_string()};
    const int NUMBER_OF_OPERATIONS {read_a_number()};

    const Append_And_Delete OBJ(INITIAL_STRING, FINAL_STRING, NUMBER_OF_OPERATIONS);
    const bool RESPONSE {OBJ.get_response()};
    print_output(RESPONSE);

    return 0;
}

    string read_a_string() {
        string word;
        cin >> word;
        return word;
    }

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    void print_output(const bool RESPONSE) {
        cout << (RESPONSE ? "Yes\n" : "No\n");
    }
