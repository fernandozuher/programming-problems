# https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

def main
  n, n_rotation, n_queries = read_numbers
  arr = read_numbers
  queries = n_queries.times.map { gets.to_i }

  r = n_rotation % n
  puts queries.map! { |q| arr[q - r] }
end

def read_numbers
  gets.split.map(&:to_i)
end

main if __FILE__ == $PROGRAM_NAME
