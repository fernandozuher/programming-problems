#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

def main
    inputLine = readLineAsIntArray
    maximumHeightCanJump = inputLine.last

    hurdlesHeights = readLineAsIntArray

    result = Result.new hurdlesHeights, maximumHeightCanJump
end

    def readLineAsIntArray
        inputLine = gets.split.map(&:to_i)
    end

    class Result

        def initialize hurdlesHeights, maximumHeightCanJump
            @hurdlesHeights = hurdlesHeights
            @maximumHeightCanJump = maximumHeightCanJump
            @doses = 0

            _hurdleRace
            printResult
        end
            private def _hurdleRace
                highestHurdle = @hurdlesHeights.max
                @doses = highestHurdle > @maximumHeightCanJump ? highestHurdle - @maximumHeightCanJump : 0
            end

            def printResult
                puts @doses
            end
    end

main
