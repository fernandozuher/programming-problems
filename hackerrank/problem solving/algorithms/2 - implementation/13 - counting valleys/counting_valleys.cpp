// Source: https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Result {

private:
    string _steps;
    int _traversed_valleys;

    void _counting_valleys() {
        int current_altitude {0};
        for (char step : _steps) {
            bool was_travessing_a_valley {current_altitude < 0};
            current_altitude += step == 'D' ? -1 : 1;
            
            if (_is_in_sea_level_from_valley(was_travessing_a_valley, current_altitude))
                _traversed_valleys++;
        }
    }

        bool _is_in_sea_level_from_valley(const bool was_travessing_a_valley, const int current_altitude) const {
            return was_travessing_a_valley && !current_altitude;
        }

public:
    Result(const string steps): _steps{steps} {
        _traversed_valleys = 0;

        _counting_valleys();
        print_result();
    }

        void print_result() const {
            cout << _traversed_valleys;
        }
};

vector<int> read_line_as_vector_int() {
    vector<int> input_line;
    string line;
    getline(cin, line);
    stringstream ss(line);

    for (int number; ss >> number; input_line.push_back(number));
    return input_line;
}

string read_line_as_string() {
    string input_line;
    getline(cin, input_line);
    return input_line;
}

int main() {
    read_line_as_vector_int();
    string steps {read_line_as_string()};

    Result result(steps);

    return 0;
}
