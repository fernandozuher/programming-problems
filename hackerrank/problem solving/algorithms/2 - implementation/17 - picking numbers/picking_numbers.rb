#!/bin/ruby

# Source:

def main
    readLineAsIntArray

    numbers = readLineAsIntArray
    numbers = numbers.sort

    result = Result.new numbers
end

    def readLineAsIntArray
        inputLine = gets.split.map(&:to_i)
    end

    class Result

        def initialize numbers
            @numbers = numbers
            @subarrayBiggestSize = 1

            _pickingNumbers
            printResult
        end

            private def _pickingNumbers
                firstReferenceNumberIndex = 0
                secondReferenceNumberIndex = 0
                subarrayCurrentSize = 1

                for i in 1..(@numbers.size - 1)
                    difference = @numbers[i] - @numbers[firstReferenceNumberIndex]

                    case difference
                        when 0
                            subarrayCurrentSize += 1

                        when 1
                            subarrayCurrentSize += 1
                            if @numbers[secondReferenceNumberIndex] != @numbers[i]
                                secondReferenceNumberIndex = i
                            end

                        else
                            @subarrayBiggestSize = _updateSubarrayBiggestSize subarrayCurrentSize
                            update = _updateFirstReferenceNumberIndexAndSubarrayCurrentSize i, secondReferenceNumberIndex

                            firstReferenceNumberIndex = update.first
                            secondReferenceNumberIndex = i
                            subarrayCurrentSize = update.last
                    end
                end

                @subarrayBiggestSize = _updateSubarrayBiggestSize(subarrayCurrentSize)
            end

                private def _updateSubarrayBiggestSize subarrayCurrentSize
                    [subarrayCurrentSize, @subarrayBiggestSize].max
                end

                private def _updateFirstReferenceNumberIndexAndSubarrayCurrentSize i, secondReferenceNumberIndex
                    firstReferenceNumberIndex, subarrayCurrentSize = 0, 0

                    if @numbers[i] - @numbers[secondReferenceNumberIndex] == 1
                        firstReferenceNumberIndex = secondReferenceNumberIndex
                        subarrayCurrentSize = i - secondReferenceNumberIndex + 1
                    else
                        firstReferenceNumberIndex = i
                        subarrayCurrentSize = 1
                    end

                    result = [firstReferenceNumberIndex, subarrayCurrentSize]
                    result
                end

            def printResult
                puts @subarrayBiggestSize
            end
    end

main
