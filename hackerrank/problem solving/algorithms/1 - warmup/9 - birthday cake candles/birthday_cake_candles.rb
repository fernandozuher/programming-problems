# https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

def main
  gets
  candles = read_numbers
  puts birthday_cake_candles(candles)
end

def read_numbers
  gets.split.map(&:to_i)
end

def birthday_cake_candles(candles)
  candles.count(candles.max)
end

main
