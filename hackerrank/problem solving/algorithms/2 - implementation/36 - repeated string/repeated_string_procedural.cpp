// Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

#include <iostream>
#include <string>

using namespace std;

string read_a_string();
unsigned long read_a_number();
unsigned long find_quantity_of_a_in_repeated_string(const string INPUT_STRING, const unsigned long N_CHARACTERS);
    unsigned long find_quantity_of_a_in_string(const string INPUT_STRING);
    unsigned long find_quantity_of_repeated_entire_string(const unsigned long N_CHARACTERS, const int SIZE_STRING);
    unsigned long find_quantity_of_remaining_a(const unsigned long N_CHARACTERS, const string INPUT_STRING);


int main() {
    const string INPUT_STRING {read_a_string()};
    const unsigned long N_CHARACTERS {read_a_number()};

    const unsigned long QUANTITY_OF_A {find_quantity_of_a_in_repeated_string(INPUT_STRING, N_CHARACTERS)};
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

    unsigned long find_quantity_of_a_in_repeated_string(const string INPUT_STRING, const unsigned long N_CHARACTERS) {
        unsigned long quantity_of_a {find_quantity_of_a_in_string(INPUT_STRING)};
        quantity_of_a *= find_quantity_of_repeated_entire_string(N_CHARACTERS, INPUT_STRING.length());
        quantity_of_a += find_quantity_of_remaining_a(N_CHARACTERS, INPUT_STRING);

        return quantity_of_a;
    }

        unsigned long find_quantity_of_a_in_string(const string INPUT_STRING) {
            unsigned long quantity_of_a {0};

            for (auto character : INPUT_STRING)
                if (character == 'a')
                    quantity_of_a++;

            return quantity_of_a;
        }

        unsigned long find_quantity_of_repeated_entire_string(const unsigned long N_CHARACTERS, const int SIZE_STRING) {
            const unsigned long N_STRINGS {N_CHARACTERS / SIZE_STRING};
            return N_STRINGS;
        }

        unsigned long find_quantity_of_remaining_a(const unsigned long N_CHARACTERS, const string INPUT_STRING) {
            const unsigned long N_REMAINING_CHARACTERS_OF_STRING {N_CHARACTERS % INPUT_STRING.length()};

            if (N_REMAINING_CHARACTERS_OF_STRING == 0)
                return 0;

            string sub_string {INPUT_STRING.substr(0, N_REMAINING_CHARACTERS_OF_STRING)};
            return find_quantity_of_a_in_string(sub_string);
        }
