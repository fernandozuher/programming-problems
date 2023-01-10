#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

def main
    inputLine = readLineAsIntArray
    n = inputLine.first

    inputLines = readCatsAndMousePositionsLines n

    result = Result.new inputLines
end

    def readLineAsIntArray
        inputLine = gets.split.map(&:to_i)
    end

    def readCatsAndMousePositionsLines n
        catsAndMousePositionsLines = Array.new(n)

        for i in 0..(n-1)
            catsAndMousePositionsLines[i] = readLineAsIntArray
        end
        
        catsAndMousePositionsLines
    end

    class Result

        def initialize catsAndMousePositionsLines
            @catsAndMousePositionsLines = catsAndMousePositionsLines
            @result = Array.new

            _catAndMouse
            printResult
        end

            private def _catAndMouse
                for catsAndMousePositions in @catsAndMousePositionsLines
                    _findNearestCatOrNot catsAndMousePositions
                end
            end

                private def _findNearestCatOrNot catsAndMousePositions
                    catAPosition = catsAndMousePositions[0]
                    catBPosition = catsAndMousePositions[1]
                    mousePosition = catsAndMousePositions[2]

                    catAPositionDifference = (catAPosition - mousePosition).abs
                    catBPositionDifference = (catBPosition - mousePosition).abs

                    _setStringResult catAPositionDifference, catBPositionDifference
                end

                    private def _setStringResult catAPositionDifference, catBPositionDifference
                        if catAPositionDifference < catBPositionDifference
                            @result.append("Cat A")
                        elsif catAPositionDifference > catBPositionDifference
                            @result.append("Cat B")
                        else
                            @result.append("Mouse C")
                        end
                    end

            def printResult
                for result in @result
                    puts result
                end
            end
    end

main
