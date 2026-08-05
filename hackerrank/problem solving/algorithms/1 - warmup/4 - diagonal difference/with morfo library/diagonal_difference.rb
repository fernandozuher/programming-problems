# https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

require 'morfo'

def main
  n = Morfo.read(&:to_i)
  puts diagonal_difference(n)
end

# T: O(n^2)
# S: O(n) extra space
def diagonal_difference(n)
  primary_sum, secondary_sum = 0, 0

  n.times do |i|
    arr = Morfo.readln(&:to_i)
    primary_sum += arr[i]
    secondary_sum += arr[-i - 1]
  end

  (primary_sum - secondary_sum).abs
end

main if __FILE__ == $0
