# https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

def main
  gets
  numbers = read_numbers
  ratios = plus_minus(numbers)
  print_ratios(ratios)
end

def read_numbers
  gets.split.map(&:to_i)
end

def plus_minus(numbers)
  positive, negative, zero = 0, 0, 0

  numbers.each do |x|
    if x > 0
      positive += 1
    elsif x < 0
      negative += 1
    else
      zero += 1
    end
  end

  n = numbers.length.to_f
  [positive / n, negative / n, zero / n]
end

def print_ratios(ratios)
  ratios.each { |ratio| printf "%.6f\n", ratio }
end

main
