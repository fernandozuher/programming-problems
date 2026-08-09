# https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

require 'morfo'

def main
  Morfo.skip_input_ln
  arr = Morfo.readln(&:to_i)
  sequence_equation(arr) { puts _1 }
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
