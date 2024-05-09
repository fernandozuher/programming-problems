# https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

def main
  n = gets.to_i
  output = Array.new(n).map! {
    amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar = gets.split.map(&:to_i)
    how_many_chocolates_can_be_eaten(amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar)
  }
  puts output
end

  def how_many_chocolates_can_be_eaten(amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar)
    eaten_chocolates = (amount_of_money / chocolate_bar_cost).to_i
    available_wrappers = eaten_chocolates

    while available_wrappers >= n_wrappers_to_turn_in_bar
      chocolates_for_free = (available_wrappers / n_wrappers_to_turn_in_bar).to_i
      available_wrappers = available_wrappers - chocolates_for_free * n_wrappers_to_turn_in_bar + chocolates_for_free
      eaten_chocolates += chocolates_for_free
    end

    eaten_chocolates
  end

main
