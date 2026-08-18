# https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

require 'morfo'

def main
  data = read_input
  charged = bon_appetit(data)
  puts Morfo.or_if_falsy(charged, "Bon Appetit")
end

def read_input
  n = Morfo.read(&:to_i)
  input = Struct.new(:item_not_eaten, :meal_costs, :amount_charged)
  input.new(item_not_eaten: Morfo.read(&:to_i), meal_costs: Morfo.read(n, &:to_i), amount_charged: Morfo.read(&:to_i))
end

# n: length of data.meal_costs
# T: O(n)
# S: O(1) extra space
def bon_appetit(data)
  total_shared_cost = data.meal_costs.sum - data.meal_costs[data.item_not_eaten]
  total_shared_cost /= 2
  data.amount_charged - total_shared_cost
end

main if __FILE__ == $0
