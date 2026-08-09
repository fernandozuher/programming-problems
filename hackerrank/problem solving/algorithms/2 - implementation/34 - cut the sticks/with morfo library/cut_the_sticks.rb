# https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

require 'morfo'

def main
  Morfo.skip_input_ln
  arr = Morfo.readln(&:to_i).sort!
  puts cut_the_sticks(arr)
end

# n: length of arr
# k: number of distinct values in arr
# k <= n
# T: O(n)
#    Sorting arr beforehand is O(n log n)
# S: O(k) = O(n) extra space
#    Sorting arr beforehand is O(n) extra space
def cut_the_sticks(arr)
  res = []
  slow, n = 0, arr.length

  n.times do |fast|
    next if arr[slow] == arr[fast]
    res << n - slow
    slow = fast
  end

  res << n - slow
end

main if __FILE__ == $0
