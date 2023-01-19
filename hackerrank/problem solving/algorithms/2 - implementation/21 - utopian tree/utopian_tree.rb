#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true


def main
    nTestCases = readLineAsInt
    nTestCasesCycles = readCycles nTestCases

    result = Result.new nTestCasesCycles
end

    def readLineAsInt
        inputLine = gets.to_i
    end

    def readCycles nTestCases
        nTestCasesCycles = Array.new nTestCases
        nTestCasesCycles = nTestCasesCycles.map {readLineAsInt}
    end

    class Result

        def initialize nTestCasesCycles
            @nTestCasesCycles = nTestCasesCycles
            @treesHeights = Array.new

            _utopianTree
            printResult
        end

            private def _utopianTree
                @treesHeights = Array.new @nTestCasesCycles.size

                for i in 0..(@treesHeights.size-1)
                    @treesHeights[i] = _calculateHeight @nTestCasesCycles[i]
                end
            end

            private def _calculateHeight cycles
                height = 1

                for cycle in 1..cycles
                    height = _isCycleHappeningDuringSpring(cycle) == true ? height * 2 : height + 1
                end

                height
            end

                def _isCycleHappeningDuringSpring cycle
                    cycle.odd?
                end

        def printResult
            puts @treesHeights
        end
    end

main
