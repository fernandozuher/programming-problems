# https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

def main
  lower = gets.to_i
  upper = gets.to_i
  valid_range = false

  lower.upto(upper) { |number|
    if is_number_kaprekar(number)
      print number, ' '
      valid_range = true
    end
  }

  unless valid_range
    puts "INVALID RANGE"
  end
end

def is_number_kaprekar(number)
  square_number = number ** 2
  divisor = 10 ** number_digits(number)
  left_number, right_number = square_number.divmod(divisor)
  number == left_number + right_number
end

def number_digits(n)
  n.to_s.length
end

main
