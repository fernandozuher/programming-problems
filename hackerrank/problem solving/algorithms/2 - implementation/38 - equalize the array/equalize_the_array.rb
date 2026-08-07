# https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

def main
  gets
  puts min_deletions_to_equalize(read_nums)
end

def read_nums = gets.split.map!(&:to_i)

# n: length of arr, 1 <= n <= 100
# k: number of distinct elements in arr
# k <= n
# T: O(n) = O(100) = O(1)
# S: O(k) = O(n) = O(100) = O(1) extra space
def min_deletions_to_equalize(arr) = arr.length - arr.tally.each_value.max

main if __FILE__ == $0
