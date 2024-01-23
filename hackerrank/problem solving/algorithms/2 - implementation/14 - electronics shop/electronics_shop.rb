# https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

def main

    budget, n_keyboard_costs, n_usb_drive_costs = read_int_array
    keyboard_costs = read_int_array
    usb_drive_costs = read_int_array

    keyboard_costs.sort!
    usb_drive_costs.sort!

    obj = Electronics_shop.new(keyboard_costs, usb_drive_costs, budget)
    puts obj.money_that_can_be_spent
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class Electronics_shop
        attr_reader :money_that_can_be_spent

        def initialize(keyboard_costs, usb_drive_costs, budget)
            @keyboard_costs = keyboard_costs
            @usb_drive_costs = usb_drive_costs
            @budget = budget
            @money_that_can_be_spent = 0
            calculate_money_spent
        end

            private def calculate_money_spent
                @keyboard_costs.each_index { |i|

                    if is_next_cost_equal_to_current_one(@keyboard_costs, i)
                        next
                    end

                    @usb_drive_costs.each_index { |j|

                        if is_next_cost_equal_to_current_one(@usb_drive_costs, j)
                            next
                        end

                        sum = @keyboard_costs[i] + @usb_drive_costs[j]

                        if is_sum_affordable_by_budget(sum)
                            @money_that_can_be_spent = update_cost(sum)
                        else
                            break
                        end
                    }

                    @money_that_can_be_spent = @money_that_can_be_spent > 0 ? @money_that_can_be_spent : -1
                }
            end

                private def is_next_cost_equal_to_current_one(device_costs, i)
                    i < device_costs.size - 1 && device_costs[i] == device_costs[i + 1]
                end

                private def is_sum_affordable_by_budget(sum)
                    sum <= @budget
                end

                private def update_cost(sum)
                    [sum, @money_that_can_be_spent].max
                end
    end

main
