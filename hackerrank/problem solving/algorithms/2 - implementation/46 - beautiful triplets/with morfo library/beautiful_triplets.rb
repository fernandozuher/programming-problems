# https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

require 'morfo'

def main
  Morfo.skip_input
  beautiful_difference = Morfo.read(&:to_i)
  arr = Morfo.readln(&:to_i)
  puts find_beautiful_triplets(arr, beautiful_difference)
end

# n: length of arr
# k: distinct numbers of arr
# k <= n
# T: O(n)
# S: O(k) = O(n) extra space
def find_beautiful_triplets(arr, beautiful_difference)
  values = arr.to_set
  double_bd = 2 * beautiful_difference
  arr.count do
    values.include?(_1 + beautiful_difference) && values.include?(_1 + double_bd)
  end
end

main if __FILE__ == $0
