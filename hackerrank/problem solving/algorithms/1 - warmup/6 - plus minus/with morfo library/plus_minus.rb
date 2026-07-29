# https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

require 'morfo'

def main
  Morfo.skip_input_ln
  arr = Morfo.readln(&:to_i)
  ratios = plus_minus(arr)
  print_ratios(ratios)
end

# n: length of arr
# T: O(n)
# S: O(1) extra space
def plus_minus(arr)
  positive, negative, zero = 0, 0, 0

  arr.each do |number|
    if number > 0
      positive += 1
    elsif number < 0
      negative += 1
    else
      zero += 1
    end
  end

  n = arr.length.to_f
  [positive / n, negative / n, zero / n]
end

def print_ratios(ratios)
  ratios.each { printf "%.6f\n", _1 }
end

main if __FILE__ == $0
