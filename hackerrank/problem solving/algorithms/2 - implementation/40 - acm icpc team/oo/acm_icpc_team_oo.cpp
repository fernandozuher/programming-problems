// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<string> read_binary_strings(const int N_STRINGS);
    string read_a_string();

class Acm_Team {
private:
    vector<string> _binary_strings;
    int _maximum_subjects_known_by_teams;
    int _teams_that_know_maximum_subjects;

    void _acm_team() {
        for (int i {0}, size_1 {static_cast<int>(_binary_strings.size()) - 1}; i < size_1; i++) {
            for (int j {i + 1}, size_2 {size_1 + 1}; j < size_2; j++) {

                const int TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS {_calculate_maximum_subjects_known_by_team(_binary_strings.at(i), _binary_strings.at(j))};

                if (TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS > _maximum_subjects_known_by_teams) {
                    _maximum_subjects_known_by_teams = {TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS};
                    _teams_that_know_maximum_subjects = {1};
                }
                else if (TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS == _maximum_subjects_known_by_teams)
                    _teams_that_know_maximum_subjects++;
            }
        }
    }

    int _calculate_maximum_subjects_known_by_team(const string BINARY_STRING_1, const string BINARY_STRING_2) const {
        int temporary_maximum_subjects_known_by_teams {0};

        for (int i {0}, size {static_cast<int>(BINARY_STRING_1.size())}; i < size; i++)
            if (BINARY_STRING_1.at(i) == '1' || BINARY_STRING_2.at(i) == '1')
                temporary_maximum_subjects_known_by_teams++;

        return temporary_maximum_subjects_known_by_teams;
    }

public:
    Acm_Team(const vector<string> BINARY_STRINGS) {
        _binary_strings = {BINARY_STRINGS};
        _teams_that_know_maximum_subjects = {0};
        _maximum_subjects_known_by_teams = {0};

        _acm_team();
    }

    int get_maximum_subjects_known_by_teams() const {
        return _maximum_subjects_known_by_teams;
    }

    int get_teams_that_know_maximum_subjects() const {
        return _teams_that_know_maximum_subjects;
    }
};

int main() {
    const int ATTENDEES {read_a_number()};
    const int _TOPICS {read_a_number()};
    const vector<string> BINARY_STRINGS {read_binary_strings(ATTENDEES)};

    const Acm_Team OBJ(BINARY_STRINGS);

    const int MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS {OBJ.get_maximum_subjects_known_by_teams()};
    const int TEAMS_THAT_KNOW_MAXIMUM_SUBJECTS {OBJ.get_teams_that_know_maximum_subjects()};
    cout << MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS << "\n" << TEAMS_THAT_KNOW_MAXIMUM_SUBJECTS << "\n";

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
