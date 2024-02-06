# https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

def main
    _, rotation_count, n_queries = read_int_array
    array = read_int_array
    queries = read_lines(n_queries)

    obj = CircularArrayRotation.new(array, rotation_count)
    print_array_according_to_index_from_another_array(obj.array, queries)
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    def read_lines(n)
        Array.new(n).map{gets.to_i}
    end

    def print_array_according_to_index_from_another_array(array1, array2)
        array2.each { |i| puts array1[i] }
    end

    class CircularArrayRotation
        attr_reader :array

        def initialize(array, rotation_count)
            @array = array
            @rotation_count = rotation_count
            reduce_rotations
            rotate_array
        end

            private def reduce_rotations
                if @array.size > 1
                    @rotation_count = @rotation_count >= @array.size ? @rotation_count % @array.size : @rotation_count
                else
                    @rotation_count = 0
                end
            end

            private def rotate_array
                first_part_new_array = @array[@array.size - @rotation_count...@array.size]
                second_part_new_array = @array[0...@array.size - @rotation_count]
                @array = first_part_new_array + second_part_new_array
            end
    end

main