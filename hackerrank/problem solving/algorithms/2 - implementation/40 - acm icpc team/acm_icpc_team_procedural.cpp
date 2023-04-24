// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<string> read_binary_strings(const int N_STRINGS);
    string read_a_string();

vector<int> acm_team(const vector<string> BINARY_STRINGS);
    int calculate_maximum_subjects_known_by_team(const string BINARY_STRING_1, const string BINARY_STRING_2);

void print_array(const vector<int> ARRAY);


int main() {
    const int ATTENDEES {read_a_number()};
    const int _TOPICS {read_a_number()};
    const vector<string> BINARY_STRINGS {read_binary_strings(ATTENDEES)};

    const vector<int> OUTPUT {acm_team(BINARY_STRINGS)};
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

    vector<int> acm_team(const vector<string> BINARY_STRINGS) {
        int teams_that_know_maximum_subjects {0};
        int maximum_subjects_known_by_teams {0};

        for (int i {0}, size_1 {static_cast<int>(BINARY_STRINGS.size()) - 1}; i < size_1; i++) {
            for (int j {i + 1}, size_2 {size_1 + 1}; j < size_2; j++) {

                const int TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS {calculate_maximum_subjects_known_by_team(BINARY_STRINGS.at(i), BINARY_STRINGS.at(j))};

                if (TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS > maximum_subjects_known_by_teams) {
                    maximum_subjects_known_by_teams = {TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS};
                    teams_that_know_maximum_subjects = {1};
                }
                else if (TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS == maximum_subjects_known_by_teams)
                    teams_that_know_maximum_subjects++;
            }
        }

        vector<int> output {maximum_subjects_known_by_teams, teams_that_know_maximum_subjects};
        return output;
    }

        int calculate_maximum_subjects_known_by_team(const string BINARY_STRING_1, const string BINARY_STRING_2) {
            int temporary_maximum_subjects_known_by_teams {0};

            for (int i {0}, size {static_cast<int>(BINARY_STRING_1.size())}; i < size; i++)
                if (BINARY_STRING_1.at(i) == '1' || BINARY_STRING_2.at(i) == '1')
                    temporary_maximum_subjects_known_by_teams++;

            return temporary_maximum_subjects_known_by_teams;
        }

    void print_array(const vector<int> ARRAY) {
        ranges::for_each(ARRAY, [](auto element) {cout << element << "\n";});
    }
