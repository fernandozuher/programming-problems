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
            obj = ChocolateFeast.new(amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar)
            output[i] = obj.get_eaten_chocolates
        end

        output
    end

    class ChocolateFeast
        @amount_of_money
        @chocolate_bar_cost
        @n_wrappers_to_turn_in_bar
        @eaten_chocolates

        def initialize(amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar)
            @amount_of_money = amount_of_money
            @chocolate_bar_cost = chocolate_bar_cost
            @n_wrappers_to_turn_in_bar = n_wrappers_to_turn_in_bar
            @eaten_chocolates = 0

            self.calculate_how_many_chocolates_can_be_eaten
        end

            private def calculate_how_many_chocolates_can_be_eaten
                @eaten_chocolates = (@amount_of_money / @chocolate_bar_cost).to_i
                available_wrappers = @eaten_chocolates

                while available_wrappers >= @n_wrappers_to_turn_in_bar
                    chocolatesForFree = (available_wrappers / @n_wrappers_to_turn_in_bar).to_i
                    available_wrappers = available_wrappers - (chocolatesForFree * @n_wrappers_to_turn_in_bar) + chocolatesForFree
                    @eaten_chocolates += chocolatesForFree
                end
            end

        def get_eaten_chocolates
            @eaten_chocolates
        end
    end

main
