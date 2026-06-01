# https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

def main
  n, n_queries = read_numbers
  obj = DynamicArray.new(n)
  n_queries.times { obj.handle_query(read_numbers) }
  puts obj.answers
end

def read_numbers
  gets.split.map!(&:to_i)
end

class DynamicArray
  attr_reader :answers

  def initialize(n)
    @n = n
    @arr = Array.new(n).map { [] }
    @answers = []
    @last_answer = 0
  end

  def handle_query(query)
    type, x, y = query
    index = (x ^ @last_answer) % @n

    if type == 1
      @arr[index] << y
    else
      j = y % @arr[index].size
      @last_answer = @arr[index][j]
      @answers.push(@last_answer)
    end
  end
end

main if __FILE__ == $0
