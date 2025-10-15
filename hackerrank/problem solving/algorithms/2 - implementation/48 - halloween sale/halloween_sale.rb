# https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

def main
  price, discount, min_price, budget = read_numbers
  puts how_many_games_can_be_bought(price, discount, min_price, budget)
end

def read_numbers
  gets.split.map(&:to_i)
end

def how_many_games_can_be_bought(price, discount, min_price, budget)
  count = 0
  while budget >= price
    count += 1
    budget -= price
    price = [price - discount, min_price].max
  end
  count
end

main if __FILE__ == $PROGRAM_NAME
