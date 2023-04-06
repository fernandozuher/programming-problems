// Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

#include <iostream>

using namespace std;

string read_a_string();
int read_a_number();
bool append_and_delete(string initial_string, string final_string, int number_of_operations);
    int find_common_prefix_size_between_strings(const string INITIAL_STRING, const string FINAL_STRING);
    bool are_operations_suitable_to_replace_string(const int NUMBER_OF_OPERATIONS, const int COMMON_PREFIX_SIZE_BETWEEN_STRINGS);
        bool are_operations_bigger_than_zero_and_odd(const int NUMBER_OF_OPERATIONS);
        bool are_not_operations_enough_to_remove_and_replace_common_prefix(const int NUMBER_OF_OPERATIONS, const int COMMON_PREFIX_SIZE_BETWEEN_STRINGS);


int main() {
    const string INITIAL_STRING {read_a_string()};
    const string FINAL_STRING {read_a_string()};
    const int NUMBER_OF_OPERATIONS {read_a_number()};

    bool response {append_and_delete(INITIAL_STRING, FINAL_STRING, NUMBER_OF_OPERATIONS)};
    cout << (response ? "Yes\n" : "No\n");

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

    bool append_and_delete(string initial_string, string final_string, int number_of_operations) {
        const int COMMON_PREFIX_SIZE_BETWEEN_STRINGS {find_common_prefix_size_between_strings(initial_string, final_string)};
        const int SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING {static_cast<int>(initial_string.size()) - COMMON_PREFIX_SIZE_BETWEEN_STRINGS};
        const int SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING {static_cast<int>(final_string.size()) - COMMON_PREFIX_SIZE_BETWEEN_STRINGS};

        const int MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING {SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING + SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING};
        number_of_operations -= MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING;

        return are_operations_suitable_to_replace_string(number_of_operations, COMMON_PREFIX_SIZE_BETWEEN_STRINGS);
    }

        int find_common_prefix_size_between_strings(const string INITIAL_STRING, const string FINAL_STRING) {
            int size {0};
            const int INITIAL_STRING_SIZE {static_cast<int>(INITIAL_STRING.size())};
            const int FINAL_STRING_SIZE {static_cast<int>(FINAL_STRING.size())};

            while (INITIAL_STRING_SIZE != size && FINAL_STRING_SIZE != size && INITIAL_STRING.at(size) == FINAL_STRING.at(size))
                size++;
            return size;
        }

        bool are_operations_suitable_to_replace_string(const int NUMBER_OF_OPERATIONS, const int COMMON_PREFIX_SIZE_BETWEEN_STRINGS) {
            if (NUMBER_OF_OPERATIONS < 0 ||
                (are_operations_bigger_than_zero_and_odd(NUMBER_OF_OPERATIONS) &&
                    are_not_operations_enough_to_remove_and_replace_common_prefix(NUMBER_OF_OPERATIONS, COMMON_PREFIX_SIZE_BETWEEN_STRINGS)))
                return false;
            return true;
        }

            bool are_operations_bigger_than_zero_and_odd(const int NUMBER_OF_OPERATIONS) {
                return NUMBER_OF_OPERATIONS > 0 && NUMBER_OF_OPERATIONS % 2 == 1;
            }

            bool are_not_operations_enough_to_remove_and_replace_common_prefix(const int NUMBER_OF_OPERATIONS, const int COMMON_PREFIX_SIZE_BETWEEN_STRINGS) {
                return NUMBER_OF_OPERATIONS < COMMON_PREFIX_SIZE_BETWEEN_STRINGS * 2;
            }
