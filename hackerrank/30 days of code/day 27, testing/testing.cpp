// https://www.hackerrank.com/challenges/30-testing/problem?isFullScreen=true
// C++20

#include <algorithm>
#include <cassert>
#include <iostream>
#include <ranges>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

struct test_case {
    vector<int> numbers;
    optional<const int> expected_result;
};

unordered_map<string, test_case> generate_test_cases();
void minimum_index_test(const test_case& test);
optional<int> find_index_of_minimum(const span<const int>& numbers);
void unique_values_test(const span<const int>& numbers);
void duplicate_minimum_value_test(const span<const int>& numbers);

int main()
{
    auto test_cases{generate_test_cases()};
    ranges::for_each(test_cases, [](const auto& pair) { minimum_index_test(pair.second); });
    unique_values_test(test_cases["unique_values"s].numbers);
    duplicate_minimum_value_test(test_cases["duplicate_minimum_value"s].numbers);
    cout << "OK";
    return 0;
}

unordered_map<string, test_case> generate_test_cases()
{
    test_case empty_numbers{.numbers{}, .expected_result{nullopt}};
    test_case unique_values{.numbers{2, 1}, .expected_result{1}};
    test_case duplicate_minimum_value{.numbers{1, 2, 1}, .expected_result{0}};
    return {
        {"empty_numbers"s, empty_numbers}, {"unique_values"s, unique_values},
        {"duplicate_minimum_value"s, duplicate_minimum_value}
    };
}

void minimum_index_test(const test_case& test)
{
    assert(find_index_of_minimum(test.numbers) == test.expected_result);
}

optional<int> find_index_of_minimum(const span<const int>& numbers)
{
    if (numbers.empty())
        return nullopt;
    return static_cast<int>(ranges::min_element(numbers) - numbers.begin());
}

void unique_values_test(const span<const int>& numbers)
{
    assert(set(numbers.begin(), numbers.end()).size() == numbers.size() && "Elements are not unique.");
}

void duplicate_minimum_value_test(const span<const int>& numbers)
{
    int min{*ranges::min_element(numbers)};
    int count{static_cast<int>(ranges::count(numbers, min))};
    assert(count == 2 && "There should be exactly two occurrences of the minimum value.");
}
