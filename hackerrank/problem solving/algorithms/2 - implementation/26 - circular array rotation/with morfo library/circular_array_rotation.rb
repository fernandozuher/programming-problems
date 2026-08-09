# https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

require 'morfo'

def main
  n = Morfo.read(&:to_i)
  n_rotation = Morfo.read(&:to_i)
  n_queries = Morfo.read(&:to_i)
  arr = Morfo.read(n, &:to_i)
  queries(arr, n_rotation, n_queries) { puts _1 }
end

# T: O(n_queries)
# S: O(1) extra space
def queries(arr, n_rotation, n_queries)
  offset = n_rotation % arr.size
  n_queries.times do
    query = Morfo.read(&:to_i)
    yield arr[query - offset]
  end
end

main if __FILE__ == $0
