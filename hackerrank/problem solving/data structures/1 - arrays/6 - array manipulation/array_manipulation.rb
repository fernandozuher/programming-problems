# https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

def main
    n, n_queries = read_int_array
    puts array_manipulation(n, n_queries)
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    def array_manipulation(n, n_queries)
        array = Array.new(n + 2, 0) # n + 2 = 1-indexed array + range-end

        n_queries.times {
            b, e, summand = read_int_array
            array[b] += summand
            array[e + 1] -= summand
        }

        sum, max = 0, 0
        for x in array
            if x == 0
                next
            end
            sum += x
            max = [max, sum].max
        end
        
        max
    end

main
