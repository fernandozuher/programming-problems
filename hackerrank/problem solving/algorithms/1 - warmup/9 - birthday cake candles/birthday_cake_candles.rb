# https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

def main
    n = gets.to_i
    array = read_int_array
    puts birthday_cake_candles(array)
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    def birthday_cake_candles(candles)
        candles.count(candles.max)
    end

main
