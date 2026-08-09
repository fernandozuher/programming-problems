# https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

require 'morfo'

def main
  n = Morfo.read(&:to_i)
  n.times do
    money, cost, wrappers_needed = Morfo.readln(&:to_i)
    puts how_many_chocolates_can_be_eaten(money, cost, wrappers_needed)
  end
end

# T: O(log(money / cost))
# S: O(1) extra space
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

main if __FILE__ == $0
