// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Angry_Professor {
public:
    Angry_Professor(const vector<int>& students_arrival_time, const int cancellation_threshold);
    bool cancelled_class() const;

private:
    vector<int> students_arrival_time;
    int cancellation_threshold;
    bool cancelled;

    void check_if_class_is_cancelled();
    int count_early_arrival_time() const;
};

    Angry_Professor::Angry_Professor(const vector<int>& students_arrival_time, const int cancellation_threshold):
        students_arrival_time{students_arrival_time}, cancellation_threshold{cancellation_threshold},
        cancelled{}
    {
        check_if_class_is_cancelled();
    }

        void Angry_Professor::check_if_class_is_cancelled()
        {
            cancelled = count_early_arrival_time() < cancellation_threshold;
        }

            int Angry_Professor::count_early_arrival_time() const
            {
                int early_arrival_time_count{};

                for (const auto arrival_time : students_arrival_time)
                    if (arrival_time <= 0)
                        ++early_arrival_time_count;

                return early_arrival_time_count;
            }

    bool Angry_Professor::cancelled_class() const
    {
        return cancelled;
    }

//////////////////////////////////////////////////

template<class T = int>
vector<T> read(const int n = 0);

int main()
{
    int n;
    cin >> n;
    vector<bool> cancelled_classes(n);

    for (auto&& cancelled : cancelled_classes) {
        int n_students_arrival_time, cancellation_threshold;
        cin >> n_students_arrival_time >> cancellation_threshold;
        vector<int> students_arrival_time {read(n_students_arrival_time)};

        Angry_Professor angry_professor{students_arrival_time, cancellation_threshold};
        cancelled = angry_professor.cancelled_class();
    }

    for (const auto cancelled : cancelled_classes)
        cout << (cancelled ? "YES" : "NO") << '\n';

    return 0;
}

    template<class T = int>
    vector<T> read(const int n)
    {
        vector<T> array(n);

        if (n)
            ranges::generate(array, [] {T x; cin >> x; return x;});
        else {
            string line;
            getline(cin, line);
            istringstream is{line};
            for (T x; is >> x; array.push_back(x));
        }

        return array;
    }
