// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

#include <algorithm>
#include <array>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

constexpr int test_case_size {5};

class Taum_And_Bday {
public:    
    explicit Taum_And_Bday(const array<long, test_case_size>& input);
    long minimum_cost_of_buying_gifts() const;
    void calculate_min_cost_of_buying_gifts();

private:
    long n_black_gifts {}, n_white_gifts {};
    long black_gift_cost {}, white_gift_cost {};
    long cost_to_convert_between_gifts {};

    long cost_to_convert_from_black_to_white {}, cost_to_convert_from_white_to_black {};

    long min_cost_of_buying_gifts {};

    bool are_original_costs_cheaper_or_equal_than_convertion_between_gifts() const;
    long calculate_minimum_standard_cost() const;
    long calculate_minimum_cost_in_converting_gifts() const;
};

    Taum_And_Bday::Taum_And_Bday(const array<long, test_case_size>& input)
    {
        tie(n_black_gifts, n_white_gifts, black_gift_cost, white_gift_cost, cost_to_convert_between_gifts) = tuple_cat(input);
        cost_to_convert_from_black_to_white = black_gift_cost + cost_to_convert_between_gifts;
        cost_to_convert_from_white_to_black = white_gift_cost + cost_to_convert_between_gifts;
    }

    long Taum_And_Bday::minimum_cost_of_buying_gifts() const
    {
        return min_cost_of_buying_gifts;
    }

    void Taum_And_Bday::calculate_min_cost_of_buying_gifts()
    {
        min_cost_of_buying_gifts = are_original_costs_cheaper_or_equal_than_convertion_between_gifts() ?
                                   calculate_minimum_standard_cost() : calculate_minimum_cost_in_converting_gifts();
    }

        bool Taum_And_Bday::are_original_costs_cheaper_or_equal_than_convertion_between_gifts() const
        {
            return white_gift_cost <= cost_to_convert_from_black_to_white && black_gift_cost <= cost_to_convert_from_white_to_black;
        }

        long Taum_And_Bday::calculate_minimum_standard_cost() const
        {
            return n_black_gifts * black_gift_cost + n_white_gifts * white_gift_cost;
        }

        long Taum_And_Bday::calculate_minimum_cost_in_converting_gifts() const
        {
            long total_gifts {n_black_gifts + n_white_gifts};
            if (white_gift_cost > cost_to_convert_from_black_to_white)
                return total_gifts * black_gift_cost + n_white_gifts * cost_to_convert_between_gifts;
            return total_gifts * white_gift_cost + n_black_gifts * cost_to_convert_between_gifts;
        }

//////////////////////////////////////////////////

array<long, test_case_size> read_test_case();

int main()
{
    long n;
    cin >> n;

    vector<long> output(n);
    ranges::generate(output, [] {
        Taum_And_Bday obj{read_test_case()};
        obj.calculate_min_cost_of_buying_gifts();
        return obj.minimum_cost_of_buying_gifts();
    });

    ranges::for_each(output, [](const auto x) {cout << x << '\n';});

    return 0;
}

    array<long, test_case_size> read_test_case()
    {
        array<long, test_case_size> array;
        ranges::generate(array, [] {long x; cin >> x; return x;});
        return array;
    }
