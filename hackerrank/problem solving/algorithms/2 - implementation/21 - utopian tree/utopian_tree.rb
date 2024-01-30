# https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

def main
    n = gets.to_i
    test_cases = read_lines(n)
    obj = Utopian_tree.new(test_cases)
    puts obj.trees_heights
end

    def read_lines(n)
        Array.new(n).map{gets.to_i}
    end

    class Utopian_tree
        attr_reader :trees_heights

        def initialize(test_cases)
            @test_cases = test_cases
            @trees_heights = Array.new(@test_cases.size)
            calculate_trees_heights
        end

            private def calculate_trees_heights
                for i in 0..(@trees_heights.size-1)
                    @trees_heights[i] = calculate_height(@test_cases[i])
                end
            end

                private def calculate_height(cycles)
                    height = 1
                    for cycle in 1..cycles
                        height = is_cycle_happening_during_spring(cycle) == true ? height * 2 : height + 1
                    end
                    height
                end

                    def is_cycle_happening_during_spring(cycle)
                        cycle.odd?
                    end
    end

main
