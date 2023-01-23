// Source: https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


class Angry_Professor {

private:
    int _n_students_arrival_time;
    int _cancellation_threshold;
    bool _cancelled_class;

    void _angry_professor() {
        _cancelled_class = _count_early_arrival_time() < _cancellation_threshold;
    }

        int _count_early_arrival_time() const {
            int early_arrival_time_count {0};

            for (int i {0}, student_arrival_time; i < _n_students_arrival_time; i++) {
                cin >> student_arrival_time;

                if (student_arrival_time <= 0)
                    early_arrival_time_count++;
            }

            return early_arrival_time_count;
        }

public:
    Angry_Professor() {
        cin >> _n_students_arrival_time;
        cin >> _cancellation_threshold;

        _angry_professor();
    }

    bool get_cancelled_class() {
        return _cancelled_class;
    }
};

int read_one_int() {
    int number;
    cin >> number;
    return number;
}

int main() {
    const int n_test_cases {read_one_int()};

    vector<bool> results(n_test_cases);

    for (int i {0}, n {static_cast<int>(results.size())}; i < n; i++) {
        Angry_Professor angry_professor;
        results.at(i) = angry_professor.get_cancelled_class();
    }

    for (bool result : results)
        cout << (result ? "YES" : "NO") << "\n";

    return 0;
}
