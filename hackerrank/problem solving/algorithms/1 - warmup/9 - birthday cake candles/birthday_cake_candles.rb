# https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

def main
  _n = gets.to_i
  array = gets.split.map(&:to_i)
  p birthday_cake_candles(array)
end

  def birthday_cake_candles(candles)
    max_count = 0
    max_element = 0

    candles.each do |x|
      if x > max_element
        max_element = x
        max_count = 1
      elsif x == max_element
        max_count += 1
      end
    end

    max_count
  end

main
