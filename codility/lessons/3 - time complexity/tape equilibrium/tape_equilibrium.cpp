// Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

#include <algorithm>
#include <cstdlib>
#include <numeric>

int solution(vector<int>& array)
{
    int first_part {array.front()};
    int second_part {accumulate(array.begin(), array.end(), 0) - first_part};
    int minimum_difference_between_parts {abs(first_part - second_part)};

    for (size_t i {1}, size {array.size() - 1}; i < size; ++i) {
        first_part += array.at(i);
        second_part -= array.at(i);
        const int current_minimum {abs(first_part - second_part)};
        minimum_difference_between_parts = {min(minimum_difference_between_parts, current_minimum)};
    }

    return minimum_difference_between_parts;
}
