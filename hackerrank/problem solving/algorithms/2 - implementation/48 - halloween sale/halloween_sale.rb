# https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

def main
  default_price_game, discount, minimum_price_game, budget = read_int_array
  p how_many_games_can_be_bought(default_price_game, discount, minimum_price_game, budget)
end

  def read_int_array
    gets.split.map(&:to_i)
  end

  def how_many_games_can_be_bought(default_price_game, discount, minimum_price_game, budget)
    games_can_be_bought_quantity = 0
    current_price_game = default_price_game
    current_budget = budget - default_price_game

    while current_budget >= 0
      games_can_be_bought_quantity += 1
      current_price_game -= discount
      current_budget -= [current_price_game, minimum_price_game].max
    end

    games_can_be_bought_quantity
  end

main
