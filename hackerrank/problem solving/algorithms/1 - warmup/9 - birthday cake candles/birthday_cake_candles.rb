#!/bin/ruby

#
# Complete the 'birthdayCakeCandles' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY candles as parameter.
#

def birthdayCakeCandles candles
    maxElement = candles.max
    candles.count maxElement
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

candles_count = gets.strip.to_i

candles = gets.rstrip.split.map(&:to_i)

result = birthdayCakeCandles candles

fptr.write result
fptr.write "\n"

fptr.close()
