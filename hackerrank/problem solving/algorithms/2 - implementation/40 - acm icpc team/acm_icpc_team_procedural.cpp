// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<string> read_binary_strings(const int N_STRINGS);
    string read_a_string();

vector<int> find_maximum_subjects_and_teams_that_know_them(const vector<string> BINARY_STRINGS);
    int count_subjects_known_by_2_teams(const string BINARY_STRING_1, const string BINARY_STRING_2);
    void update_maximum_subjects_and_teams_that_know_them(const int SUBJECTS_KNOWN_BY_2_TEAMS, int* maximum_subjects_known_by_teams, int* teams_that_know_maximum_subjects);

void print_array(const vector<int> ARRAY);


int main() {
    const int ATTENDEES {read_a_number()};
    const int _TOPICS {read_a_number()};
    const vector<string> BINARY_STRINGS {read_binary_strings(ATTENDEES)};

    const vector<int> OUTPUT {find_maximum_subjects_and_teams_that_know_them(BINARY_STRINGS)};
    print_array(OUTPUT);

    return 0;
}

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    vector<string> read_binary_strings(const int N_STRINGS) {
        vector<string> binary_strings(N_STRINGS);
        ranges::generate(binary_strings, read_a_string);
        return binary_strings;
    }

        string read_a_string() {
            string input_string;
            cin >> input_string;
            return input_string;
        }

    vector<int> find_maximum_subjects_and_teams_that_know_them(const vector<string> BINARY_STRINGS) {
        int maximum_subjects_known_by_teams {0};
        int teams_that_know_maximum_subjects {0};

        for (int i {0}, size_1 {static_cast<int>(BINARY_STRINGS.size()) - 1}; i < size_1; i++) {
            for (int j {i + 1}, size_2 {size_1 + 1}; j < size_2; j++) {
                const int SUBJECTS_KNOWN_BY_2_TEAMS {count_subjects_known_by_2_teams(BINARY_STRINGS.at(i), BINARY_STRINGS.at(j))};
                update_maximum_subjects_and_teams_that_know_them(SUBJECTS_KNOWN_BY_2_TEAMS, &maximum_subjects_known_by_teams, &teams_that_know_maximum_subjects);
            }
        }

        vector<int> output {maximum_subjects_known_by_teams, teams_that_know_maximum_subjects};
        return output;
    }

        int count_subjects_known_by_2_teams(const string BINARY_STRING_1, const string BINARY_STRING_2) {
            int subjects_known_by_2_teams {0};

            for (int i {0}, size {static_cast<int>(BINARY_STRING_1.size())}; i < size; i++)
                if (BINARY_STRING_1.at(i) == '1' || BINARY_STRING_2.at(i) == '1')
                    subjects_known_by_2_teams++;

            return subjects_known_by_2_teams;
        }

        void update_maximum_subjects_and_teams_that_know_them(const int SUBJECTS_KNOWN_BY_2_TEAMS, int* maximum_subjects_known_by_teams, int* teams_that_know_maximum_subjects) {
            if (SUBJECTS_KNOWN_BY_2_TEAMS > *maximum_subjects_known_by_teams) {
                *maximum_subjects_known_by_teams = {SUBJECTS_KNOWN_BY_2_TEAMS};
                *teams_that_know_maximum_subjects = {1};
            }
            else if (SUBJECTS_KNOWN_BY_2_TEAMS == *maximum_subjects_known_by_teams)
                (*teams_that_know_maximum_subjects)++;
        }

    void print_array(const vector<int> ARRAY) {
        ranges::for_each(ARRAY, [](auto element) {cout << element << "\n";});
    }
