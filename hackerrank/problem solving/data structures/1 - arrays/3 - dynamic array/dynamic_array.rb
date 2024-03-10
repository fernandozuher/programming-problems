# https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

def main
    n, n_queries = read_int_array
    obj = DynamicArray.new(n)

    n_queries.times do
        obj.handle_query(read_int_array)
    end
    puts obj.answers
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class DynamicArray
        attr_reader :answers

        def initialize(n)
            @n = n
            @array = Array.new(n).map{[]}
            @answers = []
            @last_answer = 0
        end

        def handle_query(query)
            type, x, y = query
            index = (x ^ @last_answer) % @n

            if type == 1
                @array[index].push(y)
            else
                j = y % @array[index].size
                @last_answer = @array[index][j]
                @answers.push(@last_answer)
            end
        end
    end

main
