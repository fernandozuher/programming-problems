#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

def main
    year = readLineAsIntArray

    result = Result.new year.first
end

    def readLineAsIntArray
        numbers = gets.split.map(&:to_i)
    end

    class Result

        def initialize year
            @year = year
            @date = ""
            
            dayOfProgrammer
            printResult
        end

            private def dayOfProgrammer
                if @year != 1918
                    isLeap = @year > 1918 ? isLeapGregorianYear() : isLeapJulianYear()
                    @date = isLeap ? "12.09." : "13.09."
                else
                    @date = "26.09."
                end

                @date += @year.to_s
            end
            

            def isLeapGregorianYear
                @year % 400 == 0 || (@year % 4 == 0 && @year % 100 != 0)
            end
                

            def isLeapJulianYear
                @year % 4 == 0
            end

            def printResult
                puts @date
            end
    end

main
