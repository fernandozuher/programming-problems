# https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

require 'morfo'

def main
  Morfo.skip_input_ln
  candles = Morfo.readln(&:to_i)
  puts birthday_cake_candles(candles)
end

# n: length of candles
# T: O(2n) => O(n)
# S: O(1) extra space
def birthday_cake_candles(candles) = candles.count(candles.max)

main if __FILE__ == $0
