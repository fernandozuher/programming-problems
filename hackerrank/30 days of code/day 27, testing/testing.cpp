// https://www.hackerrank.com/challenges/30-testing/problem?isFullScreen=true
// C++20

#include <algorithm>
#include <cassert>
#include <iostream>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

class Test_data_empty_array {
public:
    static vector<int> array()
    {
        return {};
    }
};

class Test_data_unique_values {
public:
    static vector<int> array()
    {
        return {2, 1};
    }

    static int expected_result()
    {
        return 1;
    }
};

class Test_data_exactly_two_different_minimums {
public:
    static vector<int> array()
    {
        return {1, 2, 1};
    }

    static int expected_result()
    {
        return 0;
    }
};

void test_with_empty_array();
int minimum_index_of_smallest_element(const vector<int>& numbers);
void test_with_unique_values();
void assert_size(const vector<int>& numbers);
void assert_vector_unique(const vector<int>& numbers);
void verify_result(const vector<int>& numbers, int expected_result);
void test_with_exactly_two_different_minimums();
void assert_two_occurrences_of_minimum(const vector<int>& numbers);

int main()
{
    try {
        test_with_empty_array();
        test_with_unique_values();
        test_with_exactly_two_different_minimums();
        cout << "OK";
        return 0;
    } catch (...) {
        cerr << "A test case failed!";
        return 1;
    }
}

void test_with_empty_array()
{
    const vector<int>& numbers{Test_data_empty_array::array()};
    assert(numbers.empty() && "The vector should be empty in this test case.");
    try {
        minimum_index_of_smallest_element(numbers);
    } catch (const invalid_argument&) {
        return;
    }
    assert(false);
}

int minimum_index_of_smallest_element(const vector<int>& numbers)
{
    if (numbers.empty())
        throw invalid_argument("Cannot get the minimum value index from an empty sequence");
    return static_cast<int>(ranges::min_element(numbers) - numbers.begin());
}

void test_with_unique_values()
{
    const vector<int>& numbers{Test_data_unique_values::array()};
    assert_size(numbers);
    assert_vector_unique(numbers);
    verify_result(numbers, Test_data_unique_values::expected_result());
}

void assert_size(const vector<int>& numbers)
{
    assert(numbers.size() >= 2 && "The vector should have at least two unique elements.");
}

void assert_vector_unique(const vector<int>& numbers)
{
    assert(set(numbers.begin(), numbers.end()).size() == numbers.size() && "Vector elements are not unique.");
}

void verify_result(const vector<int>& numbers, int expected_result)
{
    try {
        int result{minimum_index_of_smallest_element(numbers)};
        assert(result == expected_result && "Result does not match expected result.");
    } catch (invalid_argument& e) {
        cerr << e.what();
        assert(false);
    }
}

void test_with_exactly_two_different_minimums()
{
    const vector<int>& numbers{Test_data_exactly_two_different_minimums::array()};
    assert_size(numbers);
    assert_two_occurrences_of_minimum(numbers);
    verify_result(numbers, Test_data_exactly_two_different_minimums::expected_result());
}

void assert_two_occurrences_of_minimum(const vector<int>& numbers)
{
    int min1{*ranges::min_element(numbers)};
    int count{static_cast<int>(ranges::count_if(numbers, [min1](int x) { return x == min1; }))};
    assert(count == 2 && "There should be exactly two occurrences of the minimum value.");
}
