# Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

def main
    lower_limit = gets.to_i
    upper_limit = gets.to_i

    obj = KaprekarNumbers.new lower_limit, upper_limit
    print_output obj.get_kaprekar_numbers
end

    class KaprekarNumbers
        @lower_limit
        @upper_limit
        @kaprekar_numbers

        def initialize lower_limit, upper_limit
            @lower_limit = lower_limit
            @upper_limit = upper_limit
            @kaprekar_numbers = Array.new

            find_kaprekar_numbers_in_range
        end

            def find_kaprekar_numbers_in_range
                for number in @lower_limit..@upper_limit
                    potential_kaprekar_number = calculate_potential_kaprekar_number number
                    if number == potential_kaprekar_number
                        @kaprekar_numbers.append(number)
                    end
                end
            end

                def calculate_potential_kaprekar_number number
                    square_number_in_string = number.pow(2).to_s
                    length_of_number_in_string = number.to_s.size

                    left_number_in_string = get_left_number_in_string square_number_in_string, length_of_number_in_string
                    right_number_in_string = get_right_number_in_string square_number_in_string, length_of_number_in_string

                    potential_kaprekar_number = sum_numbers_in_strings left_number_in_string, right_number_in_string
                end

                    def get_left_number_in_string square_number_in_string, length_of_number_in_string
                        digits_to_skip = 0
                        digits_to_take = square_number_in_string.size - length_of_number_in_string
                        number_in_string = square_number_in_string[digits_to_skip...digits_to_take]
                    end

                    def get_right_number_in_string square_number_in_string, length_of_number_in_string
                        digits_to_skip = square_number_in_string.size - length_of_number_in_string
                        number_in_string = square_number_in_string[digits_to_skip...]
                    end

                    def sum_numbers_in_strings left_number_in_string, right_number_in_string
                        if left_number_in_string.size > 0 && right_number_in_string.size > 0
                            return left_number_in_string.to_i + right_number_in_string.to_i
                        elsif left_number_in_string.size == 0
                            return right_number_in_string.to_i
                        elsif right_number_in_string.size == 0
                            return left_number_in_string.to_i
                        end

                        return 0
                    end

        def get_kaprekar_numbers
            return @kaprekar_numbers
        end
    end

    def print_output array
        if array.size > 0
            puts array.join(' ')
        else
            puts "INVALID RANGE"
        end
    end

main
