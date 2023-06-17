# Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

def main
    _ = gets
    array = read_an_int_array
    puts find_minimum_distance(array)
end

    def read_an_int_array
        gets.split.map(&:to_i)
    end

    def find_minimum_distance(array)
        minimum_distance = 1 << 64
        elements = {}

        array.each_with_index do |element, i|
            if elements.has_key?(element)
                first_index, second_index = elements[element]

                if second_index == -1
                    elements[element][1] = second_index = i
                    minimum_distance_of_current_element = second_index - first_index
                    minimum_distance = [minimum_distance, minimum_distance_of_current_element].min
                end
            else
                elements[element] = [i, -1]
            end
        end
        
        minimum_distance != 1 << 64 ? minimum_distance : -1;
    end

main
