# Source: https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

def main
    n_test_cases = gets.to_i
    output = solve_test_cases(n_test_cases)
    puts output
end

    def solve_test_cases(n_test_cases)
        output = Array.new(n_test_cases)

        for i in 0...n_test_cases
            amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar = gets.split.map(&:to_i)
            output[i] = how_many_chocolates_can_be_eaten(amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar)
        end

        output
    end

        def how_many_chocolates_can_be_eaten(amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar)
            eaten_chocolates = (amount_of_money / chocolate_bar_cost).to_i
            available_wrappers = eaten_chocolates

            while available_wrappers >= n_wrappers_to_turn_in_bar
                chocolates_for_free = (available_wrappers / n_wrappers_to_turn_in_bar).to_i
                available_wrappers = available_wrappers - (chocolates_for_free * n_wrappers_to_turn_in_bar) + chocolates_for_free
                eaten_chocolates += chocolates_for_free
            end

            eaten_chocolates
        end

main
