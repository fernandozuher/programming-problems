# https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

def main
  _, n_rotation, n_queries = read_numbers
  arr = read_numbers
  queries(arr, n_rotation, n_queries) { puts _1 }
end

def read_numbers
  gets.split.map!(&:to_i)
end

# T: O(n_queries)
# S: O(1) extra space
def queries(arr, n_rotation, n_queries)
  offset = n_rotation % arr.size
  n_queries.times do
    query = gets.to_i
    yield arr[query - offset]
  end
end

main if __FILE__ == $0
