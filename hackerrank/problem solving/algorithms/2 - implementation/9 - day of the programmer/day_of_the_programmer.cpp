// Source: https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Result {

private:
    int _year;
    string _date;

    void day_of_programmer() {
        if (_year != 1918) {
            bool is_leap {_year > 1918 ? is_leap_gregorian_year() : is_leap_julian_year()};
            _date = is_leap ? "12.09." : "13.09.";
        }
        else
            _date = "26.09.";

        _date.append(to_string(_year));
    }

        bool is_leap_gregorian_year() const {
            return !(_year % 400) || (!(_year % 4) && _year % 100);
        }

        bool is_leap_julian_year() const {
            return !(_year % 4);
        }

public:
    Result(const int year): _year{year} {
        _date = "";
        
        day_of_programmer();
        print_result();
    }

        void print_result() const {
            cout << _date;
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
    vector<int> year {read_line_as_vector_int()};

    Result result(year.front());

    return 0;
}
