// Source: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

#include <map>
#include <vector>

using namespace std;

void set_default_zero_values(map<int, int>& counters, bool& found_max_counter, int& current_max);
vector<int> compouse_result(const bool found_max_counter, const int max,
                            const int n_counters, const map<int, int>& counters);

vector<int> solution(const int n_counters, vector<int>& array)
{
    bool found_max_counter {false};
    int max {0};
    map<int, int> counters;

    for (int current_max {0}; auto element : array)
        if (element <= n_counters) {
            if (found_max_counter)
                set_default_zero_values(counters, found_max_counter, current_max);

            if (++counters[element] > current_max)
                current_max++;
        }
        else if (!found_max_counter) {
            max += current_max;
            found_max_counter = {true};
        }

    return compouse_result(found_max_counter, max, n_counters, counters);
}

    void set_default_zero_values(map<int, int>& counters, bool& found_max_counter, int& current_max)
    {
        counters.clear();
        found_max_counter = {false};
        current_max = {0};
    }

    vector<int> compouse_result(const bool found_max_counter, const int max,
                                const int n_counters, const map<int, int>& counters)
    {
        const int initial_value {found_max_counter || max ? max : 0};
        vector<int> result(n_counters + 1, initial_value);

        if (!found_max_counter)
            for (const auto& [counter, value] : counters)
                result.at(counter) += value;

        return {result.begin() + 1, result.end()};
    }
