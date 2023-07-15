// Source: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

#include <valarray>

using namespace std;

vector<int> solution(const int n_counters, vector<int>& array)
{
    bool found_max_counter {false};
    int max {0};
    valarray<int> counters(n_counters + 1);

    for (int current_max {0}; const auto value : array)
        if (value <= n_counters) {
            if (found_max_counter) {
                counters = 0;
                found_max_counter = {false};
                current_max = {0};
            }
            if (++counters[value] > current_max)
                current_max++;
        }
        else if (!found_max_counter) {
            max += current_max;
            found_max_counter = {true};
        }

    if (found_max_counter)
        counters = max;
    else if (max)
        counters += max;

    return {begin(counters) + 1, end(counters)};
}
