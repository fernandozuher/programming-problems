// Source: https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

#include <iostream>
#include <vector>

using namespace std;

int read_a_number();
vector<int> solve_test_cases(const int n_test_cases);
    int how_many_chocolates_can_be_eaten(const int amount_of_money, const int chocolate_bar_cost, const int n_wrappers_to_turn_in_bar);

int main()
{
    const int n_test_cases {read_a_number()};
    const vector<int> output {solve_test_cases(n_test_cases)};
    for (auto& element : output) cout << element << "\n";

    return 0;
}

    int read_a_number()
    {
        int number;
        cin >> number;
        return number;
    }

    vector<int> solve_test_cases(const int n_test_cases)
    {
        vector<int> output(n_test_cases);

        for (auto& single_output : output) {
            const int amount_of_money {read_a_number()};
            const int chocolate_bar_cost {read_a_number()};
            const int n_wrappers_to_turn_in_bar {read_a_number()};
            single_output = {how_many_chocolates_can_be_eaten(amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar)};
        }

        return output;
    }

        int how_many_chocolates_can_be_eaten(const int amount_of_money, const int chocolate_bar_cost, const int n_wrappers_to_turn_in_bar)
        {
            int eaten_chocolates {amount_of_money / chocolate_bar_cost};

            for (int available_wrappers {eaten_chocolates}; available_wrappers >= n_wrappers_to_turn_in_bar; ) {
                const int chocolates_for_free = {available_wrappers / n_wrappers_to_turn_in_bar};
                available_wrappers = {available_wrappers - (chocolates_for_free * n_wrappers_to_turn_in_bar) + chocolates_for_free};
                eaten_chocolates += chocolates_for_free;
            }

            return eaten_chocolates;
        }
