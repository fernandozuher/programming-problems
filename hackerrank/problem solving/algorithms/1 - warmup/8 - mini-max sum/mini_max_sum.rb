# https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

def main
  arr = read_nums
  min_sum, max_sum = calc_min_max_sum(arr)
  puts "#{min_sum} #{max_sum}"
end

def read_nums = gets.split.map!(&:to_i)

# n: length of arr
# T: O(n)
# S: O(1) extra space
def calc_min_max_sum(arr)
  total = min_value = max_value = arr.first

  1.upto(arr.length - 1) do |i|
    x = arr[i]
    total += x
    min_value = [x, min_value].min
    max_value = [x, max_value].max
  end

  [total - max_value, total - min_value]
end

main if __FILE__ == $0
