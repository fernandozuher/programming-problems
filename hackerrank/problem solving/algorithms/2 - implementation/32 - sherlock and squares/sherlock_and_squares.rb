# https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

def main
    n = gets.to_i
    output = Array.new(n)

    output.map! {|x|
        n_begin, n_end = read_int_array
        obj = SherlockAndSquares.new(n_begin, n_end)
        element = obj.square_integers
    }

    puts output
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class SherlockAndSquares
        attr_reader :square_integers

        def initialize n_begin, n_end
            @n_begin = n_begin
            @n_end = n_end
            @square_integers = 0
            calculate_quantity_of_square_integers_in_range
        end

            private def calculate_quantity_of_square_integers_in_range
                number = find_first_square_integer
                while is_power_of_2_less_than_or_equal_to_limit(number)
                    @square_integers += 1
                    number += 1
                end
            end

                private def find_first_square_integer
                    square_root = Math.sqrt(@n_begin)
                    integer_part = square_root.truncate
                    square_root == integer_part ? integer_part : integer_part + 1
                end

                private def is_power_of_2_less_than_or_equal_to_limit(x)
                    x.pow(2) <= @n_end
                end
    end

main
