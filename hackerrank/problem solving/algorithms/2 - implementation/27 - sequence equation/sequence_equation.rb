# https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

def main
  gets
  arr = read_numbers
  sequence_equation(arr) { puts _1 }
end

def read_numbers
  gets.split.map!(&:to_i)
end

# n: length of arr
# T: O(n)
# S: O(n) extra space
def sequence_equation(arr)
  values_to_index = Array.new(arr.size)
  arr.each_with_index { values_to_index[_1 - 1] = _2 }
  values_to_index.each { yield values_to_index[_1] + 1 }
end

main if __FILE__ == $0
