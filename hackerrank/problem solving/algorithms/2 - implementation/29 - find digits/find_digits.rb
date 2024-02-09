# https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

def main
    n = gets.to_i
    n_number_divisors = Array.new(n)

    n.times do |i|
        number = gets.to_i
        obj = FindDigits.new(number)
        n_number_divisors[i] = obj.divisors
    end

    puts n_number_divisors
end

    class FindDigits
        @number
        @divisors

        attr_reader :divisors

        def initialize(number)
            @number = number
            @divisors = 0
            find_number_divisors_quantity
        end

            def find_number_divisors_quantity
                current_number = @number

                while current_number != 0
                    divisor = get_last_digit_of_number(current_number)

                    if is_number_evenly_divided_by_divisor(divisor)
                        @divisors += 1
                    end

                    current_number = remove_last_digit_of_number(current_number)
                end
            end

                def get_last_digit_of_number(number)
                    (number % 10).to_i
                end

                def is_number_evenly_divided_by_divisor(divisor)
                    divisor != 0 and @number % divisor == 0
                end

                def remove_last_digit_of_number(number)
                    (number / 10).to_i
                end
    end

main
