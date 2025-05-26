# https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

def main
  numbers = read_numbers
  min_sum, max_sum = calc_min_max_sum(numbers)
  puts "#{min_sum} #{max_sum}"
end

def read_numbers
  gets.split.map(&:to_i)
end

def calc_min_max_sum(numbers)
  sum = min = max = numbers.first

  numbers[1..].each do |x|
    sum += x
    min = [x, min].min
    max = [x, max].max
  end

  [sum - max, sum - min]
end

main
