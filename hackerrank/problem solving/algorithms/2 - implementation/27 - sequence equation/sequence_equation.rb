# https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

def main
    n = gets.to_i
    array = read_int_array
    obj = Sequence_equation.new(array)
    puts obj.permutated_array
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class Sequence_equation
        attr_reader :permutated_array

        def initialize array
            @array = array
            @elements_positions_array = Array.new(array.size)
            @permutated_array = Array.new(array.size)
            generate_elements_positions_array
            generate_permutated_array
        end

            def generate_elements_positions_array
                @array.each_with_index { |element, i|
                    @elements_positions_array[element-1] = i
                }
            end

            def generate_permutated_array
                @elements_positions_array.each_with_index { |element, i|
                    @permutated_array[i] = @elements_positions_array[element] + 1
                }
            end
    end

main
