# https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

def main
  gets
  arr = read_numbers
  puts a_very_big_sum(arr)
end

def read_numbers
  gets.split.map!(&:to_i)
end

# n: length of arr
# T: O(n)
# S: O(1) extra space
def a_very_big_sum(arr)
  arr.sum
end

main if __FILE__ == $0
