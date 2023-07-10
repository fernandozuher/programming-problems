// Source: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

#include  <algorithm>

int solution(vector<int> &A)
{
    ranges::sort(A);
    int unpaired_element {A.front()};
    bool is_element_paired {false};

    for (size_t i {1}; i < A.size(); ++i)
        if (A.at(i) == unpaired_element)
            is_element_paired = {!is_element_paired};
        else if (is_element_paired) {
            is_element_paired = {false};
            unpaired_element = {A.at(i)};
        }
        else
            break;

    return unpaired_element;
}
