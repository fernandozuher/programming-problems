# https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

def main
  _, n_rotation, n_queries = read_numbers
  arr = read_numbers
  queries = n_queries.times.map { gets.to_i }
  print_queries(arr, queries, n_rotation)
end

def read_numbers
  gets.split.map(&:to_i)
end

def print_queries(arr, queries, n_rotation)
  r = n_rotation % arr.size
  puts queries.map! { |q| arr[q - r] }
end

main if __FILE__ == $PROGRAM_NAME
