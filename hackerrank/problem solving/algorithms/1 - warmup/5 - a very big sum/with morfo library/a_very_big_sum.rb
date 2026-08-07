# https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

require "morfo"

def main
  Morfo.skip_input_ln
  arr = Morfo.readln(&:to_i)
  puts a_very_big_sum(arr)
end

# n: length of arr
# T: O(n)
# S: O(1) extra space
def a_very_big_sum(arr) = arr.sum

main if __FILE__ == $0
