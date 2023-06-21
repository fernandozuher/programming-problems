# Source: https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

def main
    game_default_price, discount, game_minimum_price, budget = read_an_array
    obj = HalloweenSale.new(game_default_price, discount, game_minimum_price, budget)
    puts obj.get_games_can_be_bought_quantity
end

    def read_an_array
        gets.split.map(&:to_i)
    end
    
    class HalloweenSale
        @game_default_price
        @discount
        @game_minimum_price
        @budget
        @games_can_be_bought_quantity

        def initialize(game_default_price, discount, game_minimum_price, budget)
            @game_default_price = game_default_price
            @discount = discount
            @game_minimum_price = game_minimum_price
            @budget = budget
            @games_can_be_bought_quantity = 0

            calculate_how_many_games_can_be_bought
        end

            private def calculate_how_many_games_can_be_bought
                current_game_price = @game_default_price
                current_budget = @budget - @game_default_price

                while current_budget >= 0
                    @games_can_be_bought_quantity += 1
                    current_game_price -= @discount
                    current_budget -= current_game_price >= @game_minimum_price ? current_game_price : @game_minimum_price
                end
            end

        def get_games_can_be_bought_quantity            
            @games_can_be_bought_quantity
        end
    end

main
