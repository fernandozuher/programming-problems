# https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

def main
    n = gets.to_i
    array = read_int_array
    array.sort!

    obj = PickingNumbers.new(array)
    puts obj.subarray_biggest_size
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class PickingNumbers
        attr_reader :subarray_biggest_size

        def initialize numbers
            @numbers = numbers
            @subarray_biggest_size = 1
            picking_numbers
        end

            private def picking_numbers
                first_reference_number_index = 0
                second_reference_number_index = 0
                subarray_current_size = 1

                for i in 1..(@numbers.size - 1)
                    difference = @numbers[i] - @numbers[first_reference_number_index]

                    case difference
                        when 0
                            subarray_current_size += 1

                        when 1
                            subarray_current_size += 1
                            if @numbers[second_reference_number_index] != @numbers[i]
                                second_reference_number_index = i
                            end

                        else
                            @subarray_biggest_size = update_subarray_biggest_size(subarray_current_size)
                            update = update_first_reference_number_index_and_subarray_current_size(i, second_reference_number_index)

                            first_reference_number_index = update.first
                            second_reference_number_index = i
                            subarray_current_size = update.last
                    end
                end

                @subarray_biggest_size = update_subarray_biggest_size(subarray_current_size)
            end

                private def update_subarray_biggest_size(subarray_current_size)
                    [subarray_current_size, @subarray_biggest_size].max
                end

                private def update_first_reference_number_index_and_subarray_current_size(i, second_reference_number_index)
                    first_reference_number_index, subarray_current_size = 0, 0

                    if @numbers[i] - @numbers[second_reference_number_index] == 1
                        first_reference_number_index = second_reference_number_index
                        subarray_current_size = i - second_reference_number_index + 1
                    else
                        first_reference_number_index = i
                        subarray_current_size = 1
                    end

                    [first_reference_number_index, subarray_current_size]
                end
    end

main
