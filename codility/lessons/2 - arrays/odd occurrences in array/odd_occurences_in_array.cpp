// Source: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

#include  <algorithm>

int solution(vector<int> &A) {
    ranges::sort(A);
    int unpaired_element {A.front()};
    bool is_element_paired {false};

    for (int i {1}, N {static_cast<int>(A.size())}; i < N; i++)

        if (A[i] == unpaired_element)
            is_element_paired = {!is_element_paired};
        else if (is_element_paired) {
            is_element_paired = {false};
            unpaired_element = {A[i]};
        }
        else
            break;

    return unpaired_element;
}
