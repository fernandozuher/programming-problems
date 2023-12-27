// Source: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

vector<int> read_int_array(const int n);

class Result {

public:
    Result(const vector<int> set_a, const vector<int> set_b): set_a{set_a}, set_b{set_b}, factors{0}
    {
        find_factors();
    }

        int total_factors() const
        {
            return factors;
        }

private:
    vector<int> potential_factors, set_a, set_b;
    int factors;

    void find_factors()
    {
        find_numbers_divisible_by_set_a();
        find_factors_of_set_b();
        count_factors();
    }

        void find_numbers_divisible_by_set_a()
        {
            for (int potential_factor {set_a.back()}; potential_factor <= set_b.front(); potential_factor += set_a.back()) {
                bool is_a_real_potential_factor {true};

                for (const auto element_a : set_a)
                    if (potential_factor % element_a) {
                        is_a_real_potential_factor = false;
                        break;
                    }

                if (is_a_real_potential_factor)
                    potential_factors.push_back(potential_factor);
            }
        }

        void find_factors_of_set_b()
        {
            for (const auto element_b : set_b)
                for (auto &potential_factor : potential_factors)
                    if (potential_factor && element_b % potential_factor)
                        potential_factor = 0;
        }

        void count_factors()
        {
            auto lambda_expression = [](int sum, const int item) {return item ? ++sum : sum;};
            factors = accumulate(potential_factors.begin(), potential_factors.end(), 0, lambda_expression);
        }
};

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> set_a {read_int_array(n1)};
    vector<int> set_b {read_int_array(n2)};

    ranges::sort(set_a);
    ranges::sort(set_b);

    Result result(set_a, set_b);
    cout << result.total_factors();

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        generate(array.begin(), array.end(), []{int n; cin >> n; return n;});
        return array;
    }
