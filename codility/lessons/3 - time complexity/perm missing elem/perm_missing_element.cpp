// Source: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

#include <algorithm>

int find_missing_element(const vector<int> array);


int solution(vector<int> &array) {
    ranges::sort(array);
    const int MISSING_ELEMENT {find_missing_element(array)};
    return MISSING_ELEMENT;
}

    int find_missing_element(const vector<int> array) {
        int i;
        int size {static_cast<int>(array.size())};

        for (i = {0}; i < size; i++)
            if (array.at(i) != i + 1)
                break;

        return i + 1;
    }
