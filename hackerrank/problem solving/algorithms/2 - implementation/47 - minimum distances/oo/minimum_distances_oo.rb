# Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

NO_INDEX = -1
MAX_SIZE = (1 << 64)

def main
    _ = gets
    array = read_an_int_array
    obj = MinimumDistances.new(array)
    puts obj.get_minimum_distance
end

    def read_an_int_array
        gets.split.map(&:to_i)
    end

    class MinimumDistances
        @array
        @minimum_distance

        def initialize(array)
            @array = array
            @minimum_distance = MAX_SIZE
            self.find_minimum_distance
        end

            private def find_minimum_distance
                first_indexes_of_elements = {}

                @array.each_with_index do |element, i|
                    if first_indexes_of_elements.has_key?(element)
                        first_index, second_index = first_indexes_of_elements[element]

                        if second_index == NO_INDEX
                            first_indexes_of_elements[element][1] = second_index = i
                            minimum_distance_of_current_element = second_index - first_index
                            @minimum_distance = [@minimum_distance, minimum_distance_of_current_element].min
                        end
                    else
                        first_indexes_of_elements[element] = [i, NO_INDEX]
                    end
                end
                
                @minimum_distance = self.minimum_distance_or_no_index
            end

                private def minimum_distance_or_no_index
                    @minimum_distance != MAX_SIZE ? @minimum_distance : NO_INDEX;
                end

        def get_minimum_distance
            @minimum_distance
        end
    end

main
