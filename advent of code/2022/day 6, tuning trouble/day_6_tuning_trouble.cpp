#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

class Tuning_Trouble {

private:
    int characters_before_end_of_packet_maker;
    int characters_before_end_of_message_maker;

    int count_characters_before_end_of_some_maker(const vector<string> input, const int size_packet) {
        const int initial_index {size_packet - 1};
        int last_index_of_some_maker {-1};

        for (int i {initial_index}, n {static_cast<int>(input.at(0).size())}; i < n; i++) {

            string substring {input.at(0).substr(i - initial_index, size_packet)};

            if (is_substring_like_a_set(substring)) {
                last_index_of_some_maker = i;
                break;
            }
        }
        return last_index_of_some_maker + 1;
    }

    bool is_substring_like_a_set(string substring) {
        set<char> char_set;
        for (char c : substring)
            char_set.insert(c);

        if (char_set.size() == substring.size())
            return true;
        return false;
    }

public:
    Tuning_Trouble(const vector<string> input) {
        this->characters_before_end_of_packet_maker = count_characters_before_end_of_some_maker(input, 4);
        this->characters_before_end_of_message_maker = count_characters_before_end_of_some_maker(input, 14);
        print_output();
    }

    void print_output() const {
        cout << characters_before_end_of_packet_maker << "\n" << characters_before_end_of_message_maker;
    }
};

vector<string> read_input_from_file() {
    ifstream file("input.txt");

    if (!file.is_open()) {
        cout << "\nError in opening file.\n";
        exit(EXIT_FAILURE);
    }

    vector<string> input;
    for (string line; getline(file, line); input.push_back(line));
    return input;
}

int main() {
    const vector<string> input {read_input_from_file()};
    Tuning_Trouble tuning_trouble(input);
    return 0;
}
