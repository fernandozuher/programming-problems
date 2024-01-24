# https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?is_full_screen=true

def main
    n = gets.to_i
    nearest_cats_or_not = Array.new(n)

    n.times do |i|
        positions = read_int_array
        obj = CatsAndAMouse.new(positions)
        nearest_cats_or_not[i] = obj.nearest_cat_or_not
    end

    puts nearest_cats_or_not
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class CatsAndAMouse
        attr_reader :nearest_cat_or_not

        def initialize(cats_and_mouse_positions)
            @cat_a_position, @cat_b_position, @mouse_position = cats_and_mouse_positions
            @nearest_cat_or_not = ''
            find_nearest_cat_or_not
        end

            private def find_nearest_cat_or_not
                cat_a_position_from_mouse = (@cat_a_position - @mouse_position).abs
                cat_b_position_from_mouse = (@cat_b_position - @mouse_position).abs

                if cat_a_position_from_mouse < cat_b_position_from_mouse
                    @nearest_cat_or_not = 'Cat A'
                elsif cat_a_position_from_mouse > cat_b_position_from_mouse
                    @nearest_cat_or_not = 'Cat B'
                else
                    @nearest_cat_or_not = 'Mouse C'
                end
            end
    end

main
