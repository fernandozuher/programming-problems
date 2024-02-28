# https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

def main
    n = gets.to_i
    array = read_int_array
    array.sort!

    obj = CutTheSticks.new(array)
    puts obj.remaining_sticks_length_array
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class CutTheSticks
        attr_reader :remaining_sticks_length_array

        def initialize(array)
            @sticks_length_array = array
            @remaining_sticks_length_array = [array.size]
            cut_the_sticks
        end

            def cut_the_sticks
                n = @sticks_length_array.size
                i = 0

                while i < n
                    shortest_stick_length = @sticks_length_array[i]

                    i = find_first_element_index_different_of_first_current_shortest_stick_length_index(i, n)
                    current_iterationn = n - i
                    if i == n
                        break
                    end

                    @remaining_sticks_length_array.push(current_iterationn)
                    decrease_sticks_lengths_higher_than_current_shortest_stick_length(i, n, shortest_stick_length)
                end
            end

                def find_first_element_index_different_of_first_current_shortest_stick_length_index(index, n)
                    shortest_stick_length = @sticks_length_array[index]
                    while index < n && @sticks_length_array[index] == shortest_stick_length
                        index += 1
                    end
                    index
                end

                def decrease_sticks_lengths_higher_than_current_shortest_stick_length(index, n, shortest_stick_length)
                    for i in index...n
                        @sticks_length_array[i] -= shortest_stick_length
                    end
                end
    end

main
