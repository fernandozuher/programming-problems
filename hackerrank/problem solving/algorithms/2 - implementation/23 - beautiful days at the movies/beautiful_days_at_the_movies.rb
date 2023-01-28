# Source: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

def main
    (startingDayNumber, endingDayNumber, divisor) = readLineAsIntList
    beautifulDays = BeautifulDays.new startingDayNumber, endingDayNumber, divisor
end

    def readLineAsIntList
        inputLine = gets.split.map(&:to_i)
    end

    class BeautifulDays

        def initialize startingDayNumber, endingDayNumber, divisor
            @startingDayNumber = startingDayNumber
            @endingDayNumber = endingDayNumber
            @divisor = divisor
            @nBeautifulDays = 0

            _beautifulDays
            printNBeautifulDays
        end

            def _beautifulDays
                for number in @startingDayNumber..@endingDayNumber
                    reverseNumber = _generateReverseNumber number

                    if _isDayBeautiful number, reverseNumber
                        @nBeautifulDays += 1
                    end
                end
            end

                def _generateReverseNumber number
                    reverseNumber = 0

                    while number > 0
                        reverseNumber = (reverseNumber * 10) + (number % 10)
                        number = (number / 10).to_i
                    end

                    reverseNumber
                end

                def _isDayBeautiful number, reverseNumber
                    beautifulDay = (number - reverseNumber).abs % @divisor == 0
                end

            def printNBeautifulDays
                print @nBeautifulDays
        end
    end

main
