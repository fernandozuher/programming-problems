# https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

def main
  data = read_input
  charged = bon_appetit(data)
  puts charged.zero? ? "Bon Appetit" : charged
end

def read_input
  input = Struct.new(:item_not_eaten, :meal_costs, :amount_charged)
  _, item_not_eaten = read_numbers
  meal_costs = read_numbers
  amount_charged = gets&.to_i
  input.new(item_not_eaten, meal_costs, amount_charged)
end

def read_numbers
  gets&.split&.map!(&:to_i)
end

# n: length of array data.meal_costs
# T: O(n)
# S: O(1) extra space
def bon_appetit(data)
  total_shared_cost = data.meal_costs.sum - data.meal_costs[data.item_not_eaten]
  total_shared_cost /= 2
  data.amount_charged - total_shared_cost
end

main if __FILE__ == $0
