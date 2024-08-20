// From C++23

#include <algorithm>
#include <iostream>
#include <iterator>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

vector<vector<int>> run_up_ways(int n, const vector<int>& steps_at_a_time);
void run_up_ways(int n, vector<vector<int>>& ways, const vector<int>& steps_at_a_time, vector<int>& current_way,
                 int current_step = 0);

int main()
{
    const vector steps_at_a_time{1, 2, 3};

    for (constexpr int limit{10}; const auto n : views::iota(0, limit)) {
        println("N = {}", n);
        for (const auto& way : run_up_ways(n, steps_at_a_time)) {
            ranges::copy(way, ostream_iterator<int>(cout, " -> "));
            println("");
        }
        println("");
    }

    return 0;
}

vector<vector<int>> run_up_ways(const int n, const vector<int>& steps_at_a_time)
{
    vector<vector<int>> ways;
    vector<int> current_way;
    run_up_ways(n, ways, steps_at_a_time, current_way);
    return ways;
}

void run_up_ways(const int n, vector<vector<int>>& ways, const vector<int>& steps_at_a_time, vector<int>& current_way,
                 int current_step)
{
    if (current_step == n) {
        ways.push_back(current_way);
        return;
    }

    // Since steps_at_a_time came sorted...
    for (const auto step : steps_at_a_time) {
        if (current_step + step > n)
            break;

        current_way.push_back(step);
        current_step += step;
        run_up_ways(n, ways, steps_at_a_time, current_way, current_step);
        current_way.pop_back();
        current_step -= step;
    }
}
