// Source: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Result {

private:
    vector<int> _scores;
    int _breaking_most_points_records, _breaking_least_points_records;

    void breaking_records() {
        int most_points {_scores.front()};
        int least_points {_scores.front()};        

        for (int score : _scores)
            if (score > most_points) {
                most_points = score;
                _breaking_most_points_records++;
            }
            else if (score < least_points) {
                least_points = score;
                _breaking_least_points_records++;
            }
    }

public:
    Result(const vector<int> set_a): _scores {set_a} {
        _breaking_most_points_records = _breaking_least_points_records = 0;
        breaking_records();
        print_result();
    }

        void print_result() const {
            cout << _breaking_most_points_records << " " << _breaking_least_points_records;
        }
};

vector<int> read_line_as_vector_int() {
    vector<int> numbers;
    string line;
    getline(cin, line);
    stringstream ss(line);

    for (int number; ss >> number; numbers.push_back(number));
    return numbers;
}

int main() {
    read_line_as_vector_int();
    vector<int> set_a {read_line_as_vector_int()};

    Result result(set_a);

    return 0;
}
