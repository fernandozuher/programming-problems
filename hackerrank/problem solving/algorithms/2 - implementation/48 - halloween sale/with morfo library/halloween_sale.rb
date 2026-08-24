# https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

require 'morfo'

def main
  price, discount, min_price, budget = Morfo.read(4, &:to_i)
  puts how_many_games_can_be_bought(price, discount, min_price, budget)
end

# T: O(budget / min_price)
# S: O(1) extra space
def how_many_games_can_be_bought(price, discount, min_price, budget)
  count = 0
  while budget >= price
    count += 1
    budget -= price
    price = [price - discount, min_price].max
  end
  count
end

main if __FILE__ == $0
