# https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

def main
  _, rotate_by = read_nums
  arr = read_nums
  rotate(arr, rotate_by)
  puts arr.join(' ')
end

def read_nums
  gets.split.map!(&:to_i)
end

# n: length of arr
# T: O(n)
# S: O(1) extra space
def rotate(arr, rotate_by)
  rotate_by %= arr.size if rotate_by >= arr.size
  arr.rotate!(rotate_by)
end

main if __FILE__ == $0
