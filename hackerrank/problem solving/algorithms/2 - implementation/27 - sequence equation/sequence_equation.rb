# https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

def main
  gets
  arr = read_numbers
  puts sequence_equation(arr)
end

def read_numbers
  gets&.split&.map!(&:to_i)
end

# n: length of array arr/output
# T: O(n)
# S: O(n) extra space
def sequence_equation(arr)
  values_to_index = Array.new(arr.size)
  arr.each_with_index { |val, i| values_to_index[val - 1] = i }
  values_to_index.map { |val| values_to_index[val] + 1 }
end

main if __FILE__ == $0
