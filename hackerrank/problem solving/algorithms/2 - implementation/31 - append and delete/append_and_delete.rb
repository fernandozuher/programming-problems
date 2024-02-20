# https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

def main
    initial_string = gets.strip
    final_string = gets.strip
    operations = gets.to_i
    obj = AppendAndDelete.new(initial_string, final_string, operations)
    puts obj.are_operations_suitable_to_replacement ? "Yes" : "No"
end

    class AppendAndDelete
        attr_reader :are_operations_suitable_to_replacement

        @initial_string
        @final_string
        @operations

        @common_prefix_size_between_strings
        @are_operations_suitable_to_replacement

        def initialize(initial_string, final_string, operations)
            @initial_string = initial_string
            @final_string = final_string
            @operations = operations

            @common_prefix_size_between_strings = 0
            @are_operations_suitable_to_replacement = false

            append_and_delete
        end
            
            private def append_and_delete
                @common_prefix_size_between_strings = find_common_prefix_size_between_strings

                size_of_different_characters_from_initial_string = @initial_string.size - @common_prefix_size_between_strings
                size_of_different_characters_from_final_string = @final_string.size - @common_prefix_size_between_strings

                minimal_quantity_of_operations_to_replace_string = size_of_different_characters_from_initial_string + size_of_different_characters_from_final_string
                
                @operations -= minimal_quantity_of_operations_to_replace_string
                @are_operations_suitable_to_replacement = are_operations_suitable_to_replace_string
            end

                private def find_common_prefix_size_between_strings
                    size = 0
                    n = [@initial_string.size, @final_string.size].min
                    
                    while n > 0 && @initial_string[size] == @final_string[size]
                        size += 1
                        n -= 1
                    end
                    size
                end

                private def are_operations_suitable_to_replace_string
                    if @operations < 0 ||
                        (are_operations_bigger_than_zero_and_odd && are_not_operations_enough_to_remove_and_replace_common_prefix)
                        return false
                    end
                    return true
                end

                    private def are_operations_bigger_than_zero_and_odd
                        @operations > 0 && @operations%2 == 1
                    end

                    private def are_not_operations_enough_to_remove_and_replace_common_prefix
                        @operations < @common_prefix_size_between_strings*2
                    end
    end

main
