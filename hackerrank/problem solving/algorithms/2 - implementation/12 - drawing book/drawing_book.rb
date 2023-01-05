#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true


def main
    pageQuantity = readLineAsIntArray
    page = readLineAsIntArray

    result = Result.new pageQuantity.first, page.first
end

    def readLineAsIntArray
        numbers = gets.split.map(&:to_i)
    end

    class Result

        def initialize pageQuantity, page
            @pageQuantity = pageQuantity
            @page = page
            @turnOfPagesFromFront = 0
            @turnOfPagesFromBack = 0
            @minimumTurnOfPages = 0

            _drawingBook
            printResult
        end

            private def _drawingBook
                @turnOfPagesFromFront = _calculateTurnOfPages @page
        
                maximumTurns = _calculateTurnOfPages @pageQuantity

                @turnOfPagesFromBack = maximumTurns - @turnOfPagesFromFront

                @minimumTurnOfPages = [@turnOfPagesFromFront, @turnOfPagesFromBack].min
            end

                def _calculateTurnOfPages page
                    page.odd? ? _pageIsOdd(page) : _pageIsEven(page)
                end

                    def _pageIsOdd page
                        (page - 1) / 2
                    end

                    def _pageIsEven page
                        page / 2
                    end

            def printResult
                puts @minimumTurnOfPages
            end
    end

main
