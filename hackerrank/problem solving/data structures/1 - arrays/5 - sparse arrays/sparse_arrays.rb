# https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

def main
    n = gets.to_i
    input_strings = read_input(n)
    n = gets.to_i
    result = read_queries_and_count_matches(input_strings, n)
    puts result
end

    def read_input(n)
        map = Hash.new(0)
        n.times {
            x = gets.strip
            x = x.to_sym
            map[x] += 1

        }
        map
    end

    def read_queries_and_count_matches(input_strings, n)
        result = Array.new(n)
        result.size.times { |i|
            query = gets.strip
            result[i] = input_strings[query.to_sym]
        }
        result
    end

main
