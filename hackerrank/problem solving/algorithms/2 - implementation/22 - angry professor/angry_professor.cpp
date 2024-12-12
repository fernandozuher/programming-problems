// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true
// From C++20 onwards

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct input {
    int n_students_arrival_time{}, cancellation_threshold{};
    vector<int> students_arrival_time;
};

input read_input();
template <class T = int>
vector<T> read(int n);
bool is_class_cancelled(const input& data);
void print_output(const vector<bool>& array);

int main()
{
    int n;
    cin >> n;
    vector<bool> cancelled_classes(n);
    ranges::generate(cancelled_classes, [] { return is_class_cancelled(read_input()); });
    print_output(cancelled_classes);
    return 0;
}

input read_input()
{
    input data;
    cin >> data.n_students_arrival_time >> data.cancellation_threshold;
    data.students_arrival_time = read(data.n_students_arrival_time);
    return data;
}

template <class T>
vector<T> read(const int n)
{
    vector<T> array(n);
    copy_n(istream_iterator<T>(cin), n, array.begin());
    return array;
}

bool is_class_cancelled(const input& data)
{
    int count_early_arrival_time = ranges::count_if(data.students_arrival_time, [](const auto x) { return x <= 0; });
    return count_early_arrival_time < data.cancellation_threshold;
}

void print_output(const vector<bool>& array)
{
    auto yes_or_no{[](const auto x) { return x ? "YES"s : "NO"s; }};
    ranges::transform(array, ostream_iterator<string>(cout, "\n"), yes_or_no);
}
