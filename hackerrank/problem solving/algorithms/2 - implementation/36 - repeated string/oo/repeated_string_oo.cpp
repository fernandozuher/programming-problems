// Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

#include <iostream>
#include <string>

using namespace std;

string read_a_string();
unsigned long read_a_number();


class Repeated_String {

private:
    string _input_string;
    unsigned long _n_characters;
    unsigned long _quantity_of_a;

    void _find_quantity_of_a_in_repeated_string() {
        _quantity_of_a = {_find_quantity_of_a_in_string(_input_string)};
        _quantity_of_a *= _find_quantity_of_repeated_entire_string();
        _quantity_of_a += _find_quantity_of_remaining_a();
    }

        unsigned long _find_quantity_of_a_in_string(const string INPUT_STRING) const {
            unsigned long quantity_of_a {0};

            for (auto character : INPUT_STRING)
                if (character == 'a')
                    quantity_of_a++;

            return quantity_of_a;
        }

        unsigned long _find_quantity_of_repeated_entire_string() const {
            const unsigned long N_STRINGS {_n_characters / _input_string.length()};
            return N_STRINGS;
        }

        unsigned long _find_quantity_of_remaining_a() const {
            const unsigned long N_REMAINING_CHARACTERS_OF_STRING {_n_characters % _input_string.length()};

            if (N_REMAINING_CHARACTERS_OF_STRING == 0)
                return 0;

            const string SUB_STRING {_input_string.substr(0, N_REMAINING_CHARACTERS_OF_STRING)};
            return _find_quantity_of_a_in_string(SUB_STRING);
        }

public:
    Repeated_String(const string INPUT_STRING, const unsigned long N_CHARACTERS) {
        _input_string = {INPUT_STRING};
        _n_characters = {N_CHARACTERS};
        _quantity_of_a = {0};

        _find_quantity_of_a_in_repeated_string();
    }

    unsigned long get_quantity_of_a() const {
        return _quantity_of_a;
    }
};

int main() {
    const string INPUT_STRING {read_a_string()};
    const unsigned long N_CHARACTERS {read_a_number()};

    const Repeated_String OBJ(INPUT_STRING, N_CHARACTERS);
    const unsigned long QUANTITY_OF_A {OBJ.get_quantity_of_a()};
    cout << QUANTITY_OF_A << "\n";

    return 0;
}

    string read_a_string() {
        string input_string;
        cin >> input_string;
        return input_string;
    }

    unsigned long read_a_number() {
        unsigned long number;
        cin >> number;
        return number;
    }
