# https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

def main
  n = gets.to_i
  n.times do
    money, cost, wrappers_needed = read_numbers
    puts how_many_chocolates_can_be_eaten(money, cost, wrappers_needed)
  end
end

def read_numbers
  gets.split.map(&:to_i)
end

def how_many_chocolates_can_be_eaten(money, cost, wrappers_needed)
  chocolates = money.div(cost)
  wrappers = chocolates

  while wrappers >= wrappers_needed
    free_chocolates = wrappers.div(wrappers_needed)
    wrappers = wrappers % wrappers_needed + free_chocolates
    chocolates += free_chocolates
  end

  chocolates
end

main if __FILE__ == $PROGRAM_NAME
