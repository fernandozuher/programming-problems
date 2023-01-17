#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

def main
    inputLine1 = readLineAsIntArray
    inputLine2 = readLineAsString

    result = Result.new inputLine1, inputLine2
end

    def readLineAsIntArray
        inputLine = gets.split.map(&:to_i)
    end

    def readLineAsString
        inputLine = gets
    end

    class Result

        def initialize lettersHeights, word
            @lettersHeights = lettersHeights
            @word = word
            @area = 0

            _designerPdfViewer
            printResult
        end

            private def _designerPdfViewer
                maxHeight = 0

                @word.chars.each do |letter|
                    letterIndex = letter.ord - "a".ord
                    letterHeight = @lettersHeights[letterIndex]

                    if maxHeight < letterHeight
                        maxHeight = letterHeight
                    end
                end

                @area = maxHeight * @word.size
            end

            def printResult
                puts @area
            end
    end

main
