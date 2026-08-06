# https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

require 'morfo'

def main
  arr = Morfo.readln(&:to_i)
  min_sum, max_sum = calc_min_max_sum(arr)
  puts "#{min_sum} #{max_sum}"
end

# n: length of arr
# T: O(n)
# S: O(1) extra space
def calc_min_max_sum(arr)
  total, min_value, max_value = Morfo.reduce_many(
    arr,
    method(:add), 0,
    method(:smaller), arr[0],
    method(:larger), arr[0]
  )

  [total - max_value, total - min_value]
end

def add(a, b) = a + b
def smaller(a, b) = [a, b].min
def larger(a, b) = [a, b].max

main if __FILE__ == $0
