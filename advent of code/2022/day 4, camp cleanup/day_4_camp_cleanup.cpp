#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Camp_Cleanup {

private:
    int ranges_inside_another;
    int ranges_overlap_at_all;

    void camp_cleanup(vector<string> input) {
        for (const auto line : input) {
            vector<vector<int>> elves_ranges {find_ranges(line)};
            vector<int> output {is_range_inside_another_range(elves_ranges)};
            this->ranges_inside_another += output.at(0);
            this->ranges_overlap_at_all += output.at(1);
        }
    }

        vector<vector<int>> find_ranges(string line) {
            string delimiter {","};
            string elf1_string {line.substr(0, line.find(delimiter))};
            string elf2_string {line.substr(line.find(delimiter) + 1)};

            istringstream elf1_stream(elf1_string);
            istringstream elf2_stream(elf2_string);

            char hyphen;
            vector<int> elf1(2), elf2(2);

            elf1_stream >> elf1.at(0) >> hyphen >> elf1.at(1);
            elf2_stream >> elf2.at(0) >> hyphen >> elf2.at(1);

            vector<vector<int>> elves_ranges {elf1, elf2};
            return elves_ranges;
        }

        vector<int> is_range_inside_another_range(vector<vector<int>> elves_ranges) {
            int elf1_init {elves_ranges.at(0).front()};
            int elf1_end {elves_ranges.at(0).back()};

            int elf2_init {elves_ranges.at(1).front()};
            int elf2_end {elves_ranges.at(1).back()};

            vector<int> output {0, 0};
            bool logic1 {(elf1_init >= elf2_init && elf1_init <= elf2_end)};
            bool logic2 {(elf1_end >= elf2_init && elf1_end <= elf2_end)};
            bool logic3 {(elf2_init >= elf1_init && elf2_init <= elf1_end)};
            bool logic4 {(elf2_end >= elf1_init && elf2_end <= elf1_end)};

            if ((logic1 && logic2) || (logic3 && logic4))
                output.at(0) = 1;
        
            if ((logic1 || logic2) || (logic3 || logic4))
                output.at(1) = 1;
            
            return output;
        }

    void print_output() {
        printf("%d\n%d\n", this->ranges_inside_another, this->ranges_overlap_at_all);
    }

public:
    Camp_Cleanup(vector<string> input): ranges_inside_another{0}, ranges_overlap_at_all{0} {
        camp_cleanup(input);
        print_output();
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
    vector<string> input {read_input_from_file()};
    Camp_Cleanup reorganization(input);
    return 0;
}
