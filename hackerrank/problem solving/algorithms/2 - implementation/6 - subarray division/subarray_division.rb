# https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

def main
  gets
  chocolate_squares = read_numbers
  day_month = read_numbers
  puts birthday(chocolate_squares, day_month)
end

def read_numbers
  gets.split.map!(&:to_i)
end

# n: length of array chocolate_squares
# 1 <= n <= 100
# T: O(n) = O(100) = O(1) 
# S: O(1) extra space
def birthday(chocolate_squares, day_month)
  day, month = day_month
  return 0 if month > chocolate_squares.size

  sum = chocolate_squares.lazy.take(month).sum
  count = sum == day ? 1 : 0

  (month...chocolate_squares.size).each do |i|
    sum += chocolate_squares[i] - chocolate_squares[i - month]
    count += 1 if sum == day
  end

  count
end

main if __FILE__ == $0
