// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true
// From C++20

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Between_Two_Sets {
public:
    Between_Two_Sets(const vector<int>& set_a, const vector<int>& set_b);
    [[nodiscard]] int find_factors();
        [[nodiscard]] int total_factors() const;

private:
    vector<int> set_a, set_b, potential_factors;
    int factors{};

    void find_numbers_divisible_by_set_a();
        [[nodiscard]] bool is_a_potential_factor(int number) const;
    void find_factors_of_set_b();
    void count_factors();
};

Between_Two_Sets::Between_Two_Sets(const vector<int>& set_a, const vector<int>& set_b): set_a{set_a}, set_b{set_b} {}

int Between_Two_Sets::find_factors()
{
    find_numbers_divisible_by_set_a();
    find_factors_of_set_b();
    count_factors();
    return total_factors();
}

    void Between_Two_Sets::find_numbers_divisible_by_set_a()
    {
        for (int number{set_a.back()}; number <= set_b.front(); number += set_a.back())
            if (is_a_potential_factor(number))
                potential_factors.push_back(number);
    }

        bool Between_Two_Sets::is_a_potential_factor(const int number) const
        {
            return ranges::none_of(set_a, [number](const auto x) { return number % x; });
        }

    void Between_Two_Sets::find_factors_of_set_b()
    {
        for (const auto x : set_b)
            for (auto& potential_factor : potential_factors)
                if (potential_factor && x % potential_factor)
                    potential_factor = 0;
    }

    void Between_Two_Sets::count_factors()
    {
        auto not_zero = [](const auto x) { return x; };
        factors = static_cast<int>(ranges::count_if(potential_factors, not_zero));
    }

    [[nodiscard]] int Between_Two_Sets::total_factors() const
    {
        return factors;
    }

//////////////////////////////////////////////////

template<class T = int>
vector<T> read(int n);

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector set_a{read(n1)};
    vector set_b{read(n2)};

    ranges::sort(set_a);
    ranges::sort(set_b);

    cout << Between_Two_Sets{set_a, set_b}.find_factors();

    return 0;
}

    template<class T>
    vector<T> read(const int n)
    {
        vector<T> array(n);
        copy_n(istream_iterator<T>(cin), n, array.begin());
        return array;
    }
