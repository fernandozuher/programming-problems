# https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

def main
  gets
  chocolate_squares = read_int_array
  day_month = read_int_array
  p birthday(chocolate_squares, day_month)
end

  def read_int_array
    gets.split.map(&:to_i)
  end

  def birthday(chocolate_squares, day_month)
    ways_bar_can_be_divided = 0
    day, month = day_month

    (chocolate_squares.size - month + 1).times { |i|
      if chocolate_squares[i...i + month].sum == day
        ways_bar_can_be_divided += 1
      end
    }

    ways_bar_can_be_divided
  end

main
