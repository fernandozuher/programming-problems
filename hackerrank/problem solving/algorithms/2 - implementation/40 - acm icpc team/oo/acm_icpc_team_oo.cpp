// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<string> read_binary_strings(const int N_STRINGS);
    string read_a_string();

class ACM_ICPC_TEAM {
private:
    vector<string> _binary_strings;
    int _maximum_subjects_known_by_teams;
    int _teams_that_know_maximum_subjects;

    void _find_maximum_subjects_and_teams_that_know_them() {
        for (int i {0}, size_1 {static_cast<int>(_binary_strings.size()) - 1}; i < size_1; i++)
            for (int j {i + 1}, size_2 {size_1 + 1}; j < size_2; j++) {
                const int SUBJECTS_KNOWN_BY_2_TEAMS {_count_subjects_known_by_2_teams(_binary_strings.at(i), _binary_strings.at(j))};
                _update_maximum_subjects_and_teams_that_know_them(SUBJECTS_KNOWN_BY_2_TEAMS);
            }
    }

        int _count_subjects_known_by_2_teams(const string BINARY_STRING_1, const string BINARY_STRING_2) const {
            int subjects_known_by_2_teams {0};

            for (int i {0}, size {static_cast<int>(BINARY_STRING_1.size())}; i < size; i++)
                if (BINARY_STRING_1.at(i) == '1' || BINARY_STRING_2.at(i) == '1')
                    subjects_known_by_2_teams++;

            return subjects_known_by_2_teams;
        }

        void _update_maximum_subjects_and_teams_that_know_them(const int SUBJECTS_KNOWN_BY_2_TEAMS) {
            if (SUBJECTS_KNOWN_BY_2_TEAMS > _maximum_subjects_known_by_teams) {
                _maximum_subjects_known_by_teams = {SUBJECTS_KNOWN_BY_2_TEAMS};
                _teams_that_know_maximum_subjects = {1};
            }
            else if (SUBJECTS_KNOWN_BY_2_TEAMS == _maximum_subjects_known_by_teams)
                _teams_that_know_maximum_subjects++;
        }

public:
    ACM_ICPC_TEAM(const vector<string> BINARY_STRINGS) {
        _binary_strings = {BINARY_STRINGS};
        _maximum_subjects_known_by_teams = {0};
        _teams_that_know_maximum_subjects = {0};

        _find_maximum_subjects_and_teams_that_know_them();
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

    const ACM_ICPC_TEAM OBJ(BINARY_STRINGS);
    cout << OBJ.get_maximum_subjects_known_by_teams() << "\n" << OBJ.get_teams_that_know_maximum_subjects() << "\n";

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
