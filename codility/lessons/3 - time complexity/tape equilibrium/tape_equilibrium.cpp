// Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

#include <numeric> // accumulate()
#include <cstdlib> // abs()

int find_minimum_difference_between_two_parts_array(const vector<int> ARRAY);
    int sum_array_elements(const vector<int> ARRAY);


int solution(vector<int> &array) {
    const int MINIMUM_DIFFERENCE_BETWEEN_PARTS {find_minimum_difference_between_two_parts_array(array)};
    return MINIMUM_DIFFERENCE_BETWEEN_PARTS;
}

    int find_minimum_difference_between_two_parts_array(const vector<int> ARRAY) {
        int first_part {ARRAY.front()};
        int second_part {sum_array_elements(ARRAY) - first_part};
        int minimumDifferenceBetweenParts {abs(first_part - second_part)};

        for (int i {1}, size {static_cast<int>(ARRAY.size() - 1)}; i < size; i++) {
            first_part += ARRAY.at(i);
            second_part -= ARRAY.at(i);
            const int CURRENT_MINIMUM {abs(first_part - second_part)};

            if (minimumDifferenceBetweenParts > CURRENT_MINIMUM)
                minimumDifferenceBetweenParts = {CURRENT_MINIMUM};
        }

        return minimumDifferenceBetweenParts;
    }

        int sum_array_elements(const vector<int> ARRAY) {
            return accumulate(ARRAY.begin(), ARRAY.end(), 0);
        }
