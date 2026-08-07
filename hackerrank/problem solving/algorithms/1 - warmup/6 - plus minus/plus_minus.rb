# https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

def main
  gets
  arr = read_nums
  ratios = plus_minus(arr)
  print_ratios(ratios)
end

def read_nums = gets.split.map!(&:to_i)

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

def print_ratios(ratios) = ratios.each { printf "%.6f\n", _1 }

main if __FILE__ == $0
