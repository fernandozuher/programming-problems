# https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

def main
  gets
  candles = read_numbers
  puts birthday_cake_candles(candles)
end

def read_numbers
  gets.split.map!(&:to_i)
end

# n: length of candles
# T: O(2n) = O(n)
# S: O(1) extra space
def birthday_cake_candles(candles)
  candles.count(candles.max)
end

main if __FILE__ == $0
