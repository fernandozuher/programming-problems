# Source: https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

def main
    game_default_price, discount, game_minimum_price, budget = read_an_array
    puts how_many_games_can_be_bought(game_default_price, discount, game_minimum_price, budget)
end

    def read_an_array
        gets.split.map(&:to_i)
    end

    def how_many_games_can_be_bought(game_default_price, discount, game_minimum_price, budget)
        games_can_be_bought_quantity = 0
        current_game_price = game_default_price
        current_budget = budget - game_default_price

        while current_budget >= 0
            games_can_be_bought_quantity += 1
            current_game_price -= discount
            current_budget -= current_game_price >= game_minimum_price ? current_game_price : game_minimum_price
        end

        games_can_be_bought_quantity
    end

main
