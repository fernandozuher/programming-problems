// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    long n_black_gifts;
    long n_white_gifts;
    long black_gift_cost;
    long white_gift_cost;
    long cost_to_convert_between_gifts;
} gifts;

class Taum_And_Bday {
public:
    explicit Taum_And_Bday(const gifts &gifts_data);
    [[nodiscard]] long minimum_cost_of_buying_gifts() const;
    void calculate_min_cost_of_buying_gifts();

private:
    gifts gifts_data;
    long cost_to_convert_from_black_to_white, cost_to_convert_from_white_to_black;
    long min_cost_of_buying_gifts{};

    [[nodiscard]] bool are_original_costs_cheaper_or_equal_than_conversion_between_gifts() const;
    [[nodiscard]] long calculate_minimum_standard_cost() const;
    [[nodiscard]] long calculate_minimum_cost_in_converting_gifts() const;
};

    Taum_And_Bday::Taum_And_Bday(const gifts &gifts_data): gifts_data{gifts_data}
    {
        cost_to_convert_from_black_to_white = gifts_data.black_gift_cost + gifts_data.cost_to_convert_between_gifts;
        cost_to_convert_from_white_to_black = gifts_data.white_gift_cost + gifts_data.cost_to_convert_between_gifts;
    }

    long Taum_And_Bday::minimum_cost_of_buying_gifts() const
    {
        return min_cost_of_buying_gifts;
    }

    void Taum_And_Bday::calculate_min_cost_of_buying_gifts()
    {
        min_cost_of_buying_gifts = are_original_costs_cheaper_or_equal_than_conversion_between_gifts()
                                   ? calculate_minimum_standard_cost()
                                   : calculate_minimum_cost_in_converting_gifts();
    }

        bool Taum_And_Bday::are_original_costs_cheaper_or_equal_than_conversion_between_gifts() const
        {
            return gifts_data.white_gift_cost <= cost_to_convert_from_black_to_white &&
                   gifts_data.black_gift_cost <= cost_to_convert_from_white_to_black;
        }

        long Taum_And_Bday::calculate_minimum_standard_cost() const
        {
            return gifts_data.n_black_gifts * gifts_data.black_gift_cost +
                   gifts_data.n_white_gifts * gifts_data.white_gift_cost;
        }

        long Taum_And_Bday::calculate_minimum_cost_in_converting_gifts() const
        {
            long total_gifts{gifts_data.n_black_gifts + gifts_data.n_white_gifts};
            if (gifts_data.white_gift_cost > cost_to_convert_from_black_to_white)
                return total_gifts * gifts_data.black_gift_cost +
                       gifts_data.n_white_gifts * gifts_data.cost_to_convert_between_gifts;

            return total_gifts * gifts_data.white_gift_cost + gifts_data.n_black_gifts *
                   gifts_data.cost_to_convert_between_gifts;
        }

//////////////////////////////////////////////////

gifts read_test_case();

int main()
{
    int n;
    cin >> n;
    vector<long> output(n);

    auto min_cost_of_buying_gifts{
        [] {
            Taum_And_Bday obj{read_test_case()};
            obj.calculate_min_cost_of_buying_gifts();
            return obj.minimum_cost_of_buying_gifts();
        }
    };
    auto print{[](const auto x) { cout << x << '\n'; }};

    ranges::generate(output, min_cost_of_buying_gifts);
    ranges::for_each(output, print);

    return 0;
}

    gifts read_test_case()
    {
        gifts x;
        cin >> x.n_black_gifts >> x.n_white_gifts
            >> x.black_gift_cost >> x.white_gift_cost
            >> x.cost_to_convert_between_gifts;
        return x;
    }
