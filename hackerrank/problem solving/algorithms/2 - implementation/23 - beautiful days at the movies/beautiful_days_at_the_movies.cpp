// Source: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

#include <iostream>
#include <vector>

using namespace std;


class Beautiful_Days {

private:
    int _starting_day_number;
    int _ending_day_number;
    int _divisor;
    int _n_beautiful_days;

    void _beautiful_days() {
        for (int number = _starting_day_number; number <= _ending_day_number; number++) {
            const int reverse_number = _generate_reverse_number(number);

            if (_is_day_beautiful(number, reverse_number))
                _n_beautiful_days++;
        }
    }

        int _generate_reverse_number(int number) const {
            int reverse_number = 0;
            for (; number > 0; number /= 10)
                reverse_number = (reverse_number * 10) + (number % 10);
            return reverse_number;
        }

        bool _is_day_beautiful(const int number, const int reverse_number) const {
            bool beautiful_day = abs(number - reverse_number) % _divisor == 0;
            return beautiful_day;
        }

public:
    Beautiful_Days() {
        cin >> _starting_day_number;
        cin >> _ending_day_number;
        cin >> _divisor;
        _n_beautiful_days = 0;

        _beautiful_days();
        print_n_beautiful_days();
    }

        void print_n_beautiful_days() const {
            cout << _n_beautiful_days << "\n";
        }
};

int read_one_int() {
    int number;
    cin >> number;
    return number;
}

int main() {
    Beautiful_Days _beautiful_days;
    return 0;
}
