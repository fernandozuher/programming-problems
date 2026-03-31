# https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

def main
  lower = gets.to_i
  upper = gets.to_i
  valid_range = false

  lower.upto(upper) do
    if kaprekar_number?(_1)
      print _1, ' '
      valid_range = true
    end
  end

  unless valid_range
    puts "INVALID RANGE"
  end
end

def kaprekar_number?(n)
  square_number = n ** 2
  divisor = 10 ** number_digits(n)
  left_number, right_number = square_number.divmod(divisor)
  n == left_number + right_number
end

# log n: for calculating number of digits
# T: O(log n)
# S: O(1) extra space
def number_digits(n)
  Math.log10(n).to_i + 1
end

main if __FILE__ == $0
