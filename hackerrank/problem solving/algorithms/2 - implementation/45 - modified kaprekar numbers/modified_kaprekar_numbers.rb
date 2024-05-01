# https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

def main
  lower_limit = gets.to_i
  upper_limit = gets.to_i
  valid_range = false

  lower_limit.upto(upper_limit) { |number|
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
      if n < 10
        1
      elsif n < 100
        2
      elsif n < 1000
        3
      elsif n < 10000
        4
      elsif n < 100000
        5
      elsif n < 1000000
        6
      elsif n < 10000000
        7
      else
        8
      end
    end

main
