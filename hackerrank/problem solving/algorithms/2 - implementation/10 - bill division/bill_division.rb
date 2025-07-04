# https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

def main
  data = read_input
  print_output(BillDivision.new(data).bon_appetit)
end

def read_input
  input = Struct.new(:item_not_eaten, :meal_costs, :amount_charged)
  _, item_not_eaten = read_numbers
  input.new(item_not_eaten, read_numbers, gets.to_i)
end

def read_numbers
  gets.split.map(&:to_i)
end

class BillDivision

  def initialize(data)
    @item_not_eaten = data.item_not_eaten
    @meal_costs = data.meal_costs
    @amount_charged = data.amount_charged
  end

  def bon_appetit
    overcharged = @amount_charged - compute_actual_share
    overcharged.zero? ? nil : overcharged
  end

  private def compute_actual_share
    total_shared_cost = @meal_costs.sum - @meal_costs[@item_not_eaten]
    total_shared_cost / 2
  end
end

def print_output(charged)
  puts charged || "Bon Appetit"
end

main
