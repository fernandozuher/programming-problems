# https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

def main
  _, beautiful_difference = read_numbers
  arr = read_numbers
  puts find_beautiful_triplets(arr, beautiful_difference)
end

def read_numbers
  gets.split.map(&:to_i)
end

# n: length of array arr
# T: O(n)
# S: O(n) extra space
def find_beautiful_triplets(arr, beautiful_difference)
  values = arr.to_set
  double_bd = 2 * beautiful_difference
  arr.count do |x|
    values.include?(x + beautiful_difference) && values.include?(x + double_bd)
  end
end

main if __FILE__ == $0
