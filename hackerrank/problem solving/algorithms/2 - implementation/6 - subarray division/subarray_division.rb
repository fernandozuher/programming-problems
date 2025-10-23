# https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

def main
  gets
  chocolate_squares = read_numbers
  day_month = read_numbers
  puts birthday(chocolate_squares, day_month)
end

def read_numbers
  gets.split.map(&:to_i)
end

def birthday(chocolate_squares, day_month)
  day, month = day_month
  return 0 if month > chocolate_squares.size

  sum = chocolate_squares[...month].sum
  ways_bar_can_be_divided = sum == day ? 1 : 0

  (month...chocolate_squares.size).each do |i|
    sum += chocolate_squares[i] - chocolate_squares[i - month]
    if sum == day
      ways_bar_can_be_divided += 1
    end
  end

  ways_bar_can_be_divided
end

main if __FILE__ == $PROGRAM_NAME
