# Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

def main
    _size = readANumber
    array = readAnArray
    array = array.sort

    obj = CutTheSticks.new array
    result = obj.getRemainingSticksLengthArray
    puts result
end

    def readANumber
        gets.to_i
    end

    def readAnArray
        gets.split.map(&:to_i)
    end

    class CutTheSticks
        @sticksLengthArray
        @sizeSticksLengthArray
        @remainingSticksLengthArray

        def initialize array
            @sticksLengthArray = array
            @sizeSticksLengthArray = array.size
            _initializeRemainingSticksLengthArray
            _cutTheSticks
        end

            private def _initializeRemainingSticksLengthArray
                @remainingSticksLengthArray = [@sizeSticksLengthArray]
            end

            private def _cutTheSticks
                i = 0
                while i < @sizeSticksLengthArray
                    shortestStickLength = @sticksLengthArray[i]

                    i = _findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex i
                    currentIterationSize = @sizeSticksLengthArray - i
                    if i == @sizeSticksLengthArray
                        break
                    end

                    @remainingSticksLengthArray.append currentIterationSize
                    _decreaseSticksLengthsHigherThanCurrentShortestStickLength i, shortestStickLength
                end
            end

                private def _findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex index
                    shortestStickLength = @sticksLengthArray[index]

                    while index < @sizeSticksLengthArray and @sticksLengthArray[index] == shortestStickLength
                        index += 1
                    end

                    index
                end

                private def _decreaseSticksLengthsHigherThanCurrentShortestStickLength index, shortestStickLength
                    for i in index..(@sizeSticksLengthArray-1)
                        @sticksLengthArray[i] -= shortestStickLength
                    end
                end

        public def getRemainingSticksLengthArray
            @remainingSticksLengthArray
        end
    end

main
