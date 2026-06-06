# https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

def main
  n, n_queries = read_numbers
  puts array_manipulation(n, n_queries)
end

def read_numbers
  gets.split.map!(&:to_i)
end

# T: O(n + n_queries)
# S: O(n) extra space
def array_manipulation(n, n_queries)
  arr = populate_arr(n, n_queries)
  max_sequential_sum(arr)
end

def populate_arr(n, n_queries)
  arr = Array.new(n + 2, 0) # +2 = 1-indexed array + range-end

  n_queries.times do
    b, e, summand = read_numbers
    arr[b] += summand
    arr[e + 1] -= summand
  end

  arr
end

def max_sequential_sum(arr)
  sum, max = 0, 0

  arr.each do |x|
    next if x.zero?
    sum += x
    max = [max, sum].max
  end

  max
end

main if __FILE__ == $0
