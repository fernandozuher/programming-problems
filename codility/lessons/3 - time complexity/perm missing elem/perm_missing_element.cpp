// Source: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

#include <algorithm>

int find_missing_element(const vector<int>& array);

int solution(vector<int>& array)
{
    ranges::sort(array);
    return find_missing_element(array);
}

    int find_missing_element(const vector<int>& array)
    {
        int i {0};
        for (int size {static_cast<int>(array.size())}; i < size; ++i)
            if (array.at(i) != i + 1)
                break;
        return i + 1;
    }
