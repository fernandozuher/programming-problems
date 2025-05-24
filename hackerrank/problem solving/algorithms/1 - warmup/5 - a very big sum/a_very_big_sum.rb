# https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

def main
  gets
  numbers = read_numbers
  puts a_very_big_sum(numbers)
end

def read_numbers
  gets.split.map(&:to_i)
end

def a_very_big_sum(numbers)
  numbers.sum
end

main
