# https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

def main
  input = Struct.new(:item_anna_didnt_consume, :cost_of_each_meal, :brian_charged_anna)
  _, item_anna_didnt_consume = read_int_array
  data = input.new(item_anna_didnt_consume, read_int_array, gets.to_i)

  obj = BillDivision.new(data)
  obj.bon_appetit
  print_output(obj.brian_overcharged_anna)
end

  def read_int_array
    gets.split.map(&:to_i)
  end

  class BillDivision
    attr_reader :brian_overcharged_anna

    def initialize(data)
      @item_anna_didnt_consume = data.item_anna_didnt_consume
      @cost_of_each_meal = data.cost_of_each_meal
      @brian_charged_anna = data.brian_charged_anna
      @brian_overcharged_anna = 0
    end

    def bon_appetit
      anna_cost = calculate_anna_cost
      how_much_brian_overcharged_anna(anna_cost)
    end

      private def calculate_anna_cost
        sum = @cost_of_each_meal.sum
        (sum - @cost_of_each_meal[@item_anna_didnt_consume]) / 2
      end

    private def how_much_brian_overcharged_anna(anna_cost)
      if anna_cost != @brian_charged_anna
        @brian_overcharged_anna = @brian_charged_anna - anna_cost
      end
    end
  end

  def print_output(charged)
    puts charged > 0 ? charged : "Bon Appetit"
  end

main
