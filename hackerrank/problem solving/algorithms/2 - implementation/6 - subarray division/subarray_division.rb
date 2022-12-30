#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

def main
    readLineAsIntArray
    chocolateSquares = readLineAsIntArray
    dayMonth = readLineAsIntArray

    result = Result.new chocolateSquares, dayMonth
end

    def readLineAsIntArray
        numbers = gets.split.map(&:to_i)
    end

    class Result

        def initialize chocolateSquares, dayMonth
            @chocolateSquares = chocolateSquares
            @day = dayMonth[0]
            @month = dayMonth[1]
            @waysBarCanBeDivided = 0

            birthday
            printResult
        end

            private def birthday
                for i in 0..(@chocolateSquares.size - @month)
                    sum = 0
                    for j in i..(i + @month - 1)
                        sum += @chocolateSquares[j]
                    end

                    if sum == @day
                        @waysBarCanBeDivided += 1
                    end
                end
            end

            def printResult
                puts @waysBarCanBeDivided
            end
    end

main
