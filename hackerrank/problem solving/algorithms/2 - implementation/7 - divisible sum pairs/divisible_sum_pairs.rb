# https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

def main
    n, k = read_int_array
    array = read_int_array

    array.sort!

    obj = SubarrayDivision.new(array, k)
    puts obj.n_divisible_sum_pairs
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class SubarrayDivision

        def initialize(array, k)
            @array = array
            @k = k
            @n_divisible_sum_pairs = 0

            divisible_sum_pairs
        end

            private def divisible_sum_pairs
                for i in 0..(@array.size - 2)
                    for j in (i + 1)..(@array.size - 1)
                        if @array[i] <= @array[j] and (@array[i] + @array[j]) % @k == 0
                            @n_divisible_sum_pairs += 1;
                        end
                    end
                end
            end

        def n_divisible_sum_pairs
            @n_divisible_sum_pairs
        end
    end

main
