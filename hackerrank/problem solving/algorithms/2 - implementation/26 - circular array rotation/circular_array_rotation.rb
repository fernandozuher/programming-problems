# https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

def main
  _, n_rotation, n_queries = read_numbers
  arr = read_numbers
  print_queries(arr, n_rotation, n_queries)
end

def read_numbers
  gets.split.map(&:to_i)
end

def print_queries(arr, n_rotation, n_queries)
  r = n_rotation % arr.size
  n_queries.times do
    query = gets.to_i
    puts arr[query - r]
  end
end

main if __FILE__ == $PROGRAM_NAME
