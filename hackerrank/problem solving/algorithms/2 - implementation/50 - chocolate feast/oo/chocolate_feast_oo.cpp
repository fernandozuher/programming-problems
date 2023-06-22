// Source: https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

#include <iostream>
#include <vector>

using namespace std;

int read_a_number();
vector<int> solve_test_cases(const int n_test_cases);

class Chocolate_Feast
{
private:
    int amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar;
    int eaten_chocolates;

    void calculate_how_many_chocolates_can_be_eaten()
    {
        this->eaten_chocolates = {amount_of_money / chocolate_bar_cost};

        for (int available_wrappers {this->eaten_chocolates}; available_wrappers >= this->n_wrappers_to_turn_in_bar; ) {
            const int chocolates_for_free = {available_wrappers / this->n_wrappers_to_turn_in_bar};
            available_wrappers = {available_wrappers - (chocolates_for_free * this->n_wrappers_to_turn_in_bar) + chocolates_for_free};
            this->eaten_chocolates += chocolates_for_free;
        }
    }

public:
    Chocolate_Feast(const int amount_of_money, const int chocolate_bar_cost, const int n_wrappers_to_turn_in_bar)
        : amount_of_money{amount_of_money}, chocolate_bar_cost{chocolate_bar_cost},
          n_wrappers_to_turn_in_bar{n_wrappers_to_turn_in_bar}, eaten_chocolates{0}
    {
        this->calculate_how_many_chocolates_can_be_eaten();
    }

    int get_eaten_chocolates() const
    {
        return this->eaten_chocolates;
    }
};

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

            const Chocolate_Feast obj {amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar};
            single_output = {obj.get_eaten_chocolates()};
        }

        return output;
    }
