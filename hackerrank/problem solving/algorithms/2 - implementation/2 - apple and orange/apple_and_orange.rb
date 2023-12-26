# https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

def main()
    input = read_input
    count_apples_and_oranges(input)
end

    def read_input
        starting_sam, ending_sam = read_int_array
        apple_tree_location, orange_tree_location = read_int_array

        # Discard sizes of arrays
        read_int_array

        apples_distance_from_tree = read_int_array
        oranges_distance_from_tree = read_int_array

        Struct.new("AppleAndOrange", :starting_sam, :ending_sam,
            :apple_tree_location, :orange_tree_location,
            :apples_distance_from_tree, :oranges_distance_from_tree)

        Struct::AppleAndOrange.new(starting_sam, ending_sam,
                            apple_tree_location, orange_tree_location,
                            apples_distance_from_tree, oranges_distance_from_tree)
    end

        def read_int_array
            gets.split.map(&:to_i)
        end

    def count_apples_and_oranges(input)
        apples_on_house = count_fruits_on_house(input, 'apple')
        oranges_on_house = count_fruits_on_house(input, 'orange')
        puts "#{apples_on_house}\n#{oranges_on_house}"
    end

        def count_fruits_on_house(input, fruit)
            filtered_input = filter_input(input, fruit)
            tree_location = filtered_input.first
            fruits = filtered_input.last

            verify_fruit_location = -> (input, partial_location) {
                location = tree_location + partial_location
                location >= input.starting_sam && location <= input.ending_sam
            }

            fruits.count {|partial_location| verify_fruit_location.call(input, partial_location)}
        end

            def filter_input(input, fruit)
                data = 2
                filtered_input = * data

                if fruit == 'apple'
                    filtered_input[0] = input.apple_tree_location
                    filtered_input[1] = input.apples_distance_from_tree
                else
                    filtered_input[0] = input.orange_tree_location
                    filtered_input[1] = input.oranges_distance_from_tree
                end

                filtered_input
            end

main
