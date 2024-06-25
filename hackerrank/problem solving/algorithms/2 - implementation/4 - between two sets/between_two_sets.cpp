// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true
// From C++20

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Between_Two_Sets {
public:
    Between_Two_Sets(const vector<int>& set_a, const vector<int>& set_b);
    [[nodiscard]] int total_factors() const;
    void find_factors();

private:
    vector<int> set_a, set_b, potential_factors;
    int factors{};

    void find_numbers_divisible_by_set_a();
    void find_factors_of_set_b();
    void count_factors();
};

    Between_Two_Sets::Between_Two_Sets(const vector<int>& set_a, const vector<int>& set_b): set_a{set_a}, set_b{set_b} {}

    [[nodiscard]] int Between_Two_Sets::total_factors() const
    {
        return factors;
    }

    void Between_Two_Sets::find_factors()
    {
        find_numbers_divisible_by_set_a();
        find_factors_of_set_b();
        count_factors();
    }

        void Between_Two_Sets::find_numbers_divisible_by_set_a()
        {
            for (int potential_factor{set_a.back()}; potential_factor <= set_b.front(); potential_factor += set_a.back()) {
                bool is_a_real_potential_factor{true};

                for (const auto x : set_a)
                    if (potential_factor % x) {
                        is_a_real_potential_factor = false;
                        break;
                    }

                if (is_a_real_potential_factor)
                    potential_factors.push_back(potential_factor);
            }
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
            factors = static_cast<int>(ranges::count_if(potential_factors, [](const auto x){return x;}));
        }

//////////////////////////////////////////////////

vector<int> read_int_array(int n);

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector set_a{read_int_array(n1)};
    vector set_b{read_int_array(n2)};

    ranges::sort(set_a);
    ranges::sort(set_b);

    Between_Two_Sets obj{set_a, set_b};
    obj.find_factors();
    cout << obj.total_factors();

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        copy_n(istream_iterator<int>(cin), n, array.begin());
        return array;
    }
