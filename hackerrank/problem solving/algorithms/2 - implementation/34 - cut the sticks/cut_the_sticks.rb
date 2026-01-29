# https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

def main
  gets
  arr = read_numbers.sort!
  puts cut_the_sticks(arr)
end

def read_numbers
  gets&.split&.map!(&:to_i)
end

# n: length of arr
# k: number of distinct values in arr
# T: O(n)
#    Sorting arr before calling this function is O(n log n)
# S: O(k), but O(n) in the worst case extra space
#    Sorting arr before calling this function is O(n) extra space
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
