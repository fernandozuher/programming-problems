# Source: https://www.hackerrank.com/challenges/between-two-sets/problem?is_full_screen=true

def main
    read_int_array
    set_a = read_int_array
    set_b = read_int_array

    set_a = set_a.sort
    set_b = set_b.sort

    result = BetweenTwoSets.new(set_a, set_b)
    puts result.total_factors
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class BetweenTwoSets
        def initialize set_a, set_b
            @set_a = set_a
            @set_b = set_b
            @potential_factors = Array.new
            @total_factors = 0

            find_factors
        end

            private def find_factors
                find_numbers_divisible_by_set_a
                find_factors_of_set_b
                count_factors
            end
            
                private def find_numbers_divisible_by_set_a
                    for potential_factor in (@set_a.last..@set_b.first).step(@set_a.last)
                        @is_aReal_potential_factor = true

                        for element_a in @set_a
                            if (potential_factor % element_a) != 0
                                @is_aReal_potential_factor = false
                                break
                            end
                        end

                        if @is_aReal_potential_factor == true
                            @potential_factors.push(potential_factor)
                        end
                    end
                end

                private def find_factors_of_set_b
                    for element_b in @set_b
                        @potential_factors.each_with_index { |potential_factor, i|
                            if potential_factor != 0 && (element_b % potential_factor) != 0
                                @potential_factors[i] = 0
                            end
                        }
                    end
                end

                private def count_factors
                    @total_factors = @potential_factors.reduce(0) { |sum, item|
                        item != 0 ? (sum + 1) : sum
                    }
                end

            def total_factors
                @total_factors
            end
    end

main