# https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

require 'morfo'

def main
  Morfo.skip_input_ln
  puts sum_stdin
end

# n: number of integers in the input line
# T: O(n)
# S: O(n) extra space
def sum_stdin
  Morfo.readln(&:to_i).sum
end

main if __FILE__ == $0
