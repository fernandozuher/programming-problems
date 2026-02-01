# https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

def main
  gets
  puts min_deletions_to_equalize(read_numbers)
end

def read_numbers
  gets&.split&.map!(&:to_i)
end

# n: length of arr, 1 <= n <= 100
# T: O(n) = O(100) = O(1)
# S: O(n) = O(100) = O(1) extra space
def min_deletions_to_equalize(arr)
  arr.length - arr.tally.values.max
end

main if __FILE__ == $0
