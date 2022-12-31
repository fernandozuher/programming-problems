#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

def main
    input1 = readLineAsIntArray
    k = input1[1]
    numbers = readLineAsIntArray

    numbers = numbers.sort

    result = Result.new numbers, k
end

    def readLineAsIntArray
        numbers = gets.split.map(&:to_i)
    end

    class Result

        def initialize numbers, k
            @numbers = numbers
            @k = k
            @nDivisibleSumPairs = 0

            divisibleSumPairs
            printResult
        end

            private def divisibleSumPairs
                for i in 0..(@numbers.size - 2)
                    for j in (i + 1)..(@numbers.size - 1)
                        if @numbers[i] <= @numbers[j] and (@numbers[i] + @numbers[j]) % @k == 0
                            @nDivisibleSumPairs += 1;
                        end
                    end
                end
            end

            def printResult
                puts @nDivisibleSumPairs
            end
    end

main
