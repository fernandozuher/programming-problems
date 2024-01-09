# https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

def main
    n, item_anna_didnt_consume = read_int_array
    cost_of_each_meal = read_int_array
    brian_charged_anna = gets.to_i

    obj = BillDivision.new(cost_of_each_meal, item_anna_didnt_consume, brian_charged_anna)
    print_output(obj.brian_overcharged_anna)
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class BillDivision
        attr_reader :brian_overcharged_anna

        def initialize(cost_of_each_meal, item_anna_didnt_consume, brian_charged_anna)
            @cost_of_each_meal = cost_of_each_meal
            @item_anna_didnt_consume = item_anna_didnt_consume
            @brian_charged_anna = brian_charged_anna
            @brian_overcharged_anna = 0

            bon_appetit
        end

            private def bon_appetit
                anna_cost = calculate_anna_cost
                calculate_how_much_brian_overcharged_anna(anna_cost)
            end

                private def calculate_anna_cost
                    sum = @cost_of_each_meal.sum
                    anna_cost = (sum - @cost_of_each_meal[@item_anna_didnt_consume]) / 2
                end

                private def calculate_how_much_brian_overcharged_anna(anna_cost)
                    if anna_cost != @brian_charged_anna
                        @brian_overcharged_anna = @brian_charged_anna - anna_cost
                    end
                end
    end

    def print_output(charged)
        puts charged > 0 ? charged : "Bon Appetit"
    end

main
