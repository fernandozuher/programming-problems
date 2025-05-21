# https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

def main
  n = gets.to_i
  puts diagonal_difference(n)
end

def diagonal_difference(n)
  primary_sum, secondary_sum = 0, 0

  n.times do |i|
    numbers = read_numbers
    primary_sum += numbers[i]
    secondary_sum += numbers[n - i - 1]
  end

  (primary_sum - secondary_sum).abs
end

def read_numbers
  gets.split.map(&:to_i)
end

main
