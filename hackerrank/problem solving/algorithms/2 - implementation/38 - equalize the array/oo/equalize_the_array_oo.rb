# Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

def main
    _ = gets
    array = readAnArray

    obj = EqualizeTheArray.new array
    minimumNumberOfDeletionsRequired = obj.getMinimumNumberOfDeletionsRequired
    puts minimumNumberOfDeletionsRequired
end

    def readAnArray
        array = gets.split.map(&:to_i)
    end

    class EqualizeTheArray
        @array
        @minimumNumberOfDeletionsRequired

        def initialize array
            array = array.sort
            @array = array
            _equalizeArray
        end

            private def _equalizeArray
                maximumQuantityOfEqualElement = _findMaximumQuantityOfEqualElement
                @minimumNumberOfDeletionsRequired = @array.size - maximumQuantityOfEqualElement
            end

                private def _findMaximumQuantityOfEqualElement
                    maximumQuantityOfEqualElement = 1
                    temporaryQuantityEqualElement = 1

                    for i in 1..(@array.size-1)
                        if _areConsecutiveElementesEqual @array[i-1], @array[i]
                            temporaryQuantityEqualElement += 1
                            maximumQuantityOfEqualElement = [temporaryQuantityEqualElement, maximumQuantityOfEqualElement].max
                        else
                            temporaryQuantityEqualElement = 1
                        end
                    end

                    maximumQuantityOfEqualElement
                end

                    private def _areConsecutiveElementesEqual element1, element2
                        element1 == element2
                    end

        def getMinimumNumberOfDeletionsRequired
            return @minimumNumberOfDeletionsRequired
        end
    end

main
