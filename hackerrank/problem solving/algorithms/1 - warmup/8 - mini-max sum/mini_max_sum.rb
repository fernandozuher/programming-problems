# https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

def main
  arr = read_numbers
  min_sum, max_sum = calc_min_max_sum(arr)
  puts "#{min_sum} #{max_sum}"
end

def read_numbers
  gets.split.map!(&:to_i)
end

# n: length of arr
# T: O(n)
# S: O(1) extra space
def calc_min_max_sum(arr)
  sum = min = max = arr.first

  1.upto(arr.length - 1) do |i|
    x = arr[i]
    sum += x
    min = [x, min].min
    max = [x, max].max
  end

  [sum - max, sum - min]
end

main if __FILE__ == $0
