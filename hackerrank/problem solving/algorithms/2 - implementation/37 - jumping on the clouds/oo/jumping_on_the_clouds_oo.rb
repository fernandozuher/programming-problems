# Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

def main
    _ = gets.to_i
    cloudArray = readAnArray
    obj = JumpingOnTheClouds.new cloudArray
    minimumNumberOfJumps = obj.getMinimumNumberOfJumps
    puts minimumNumberOfJumps
end

    def readAnArray
        array = gets.split.map(&:to_i)
    end

    class JumpingOnTheClouds
        @cloudArray
        @minimumNumberOfJumps

        def initialize cloudArray
            @cloudArray = cloudArray
            @minimumNumberOfJumps = 0

            _calculateMinimumNumberOfJumps
        end

            def _calculateMinimumNumberOfJumps
                i = 0
                size = @cloudArray.size - 1

                while i < size
                    i = _getIndexOfNextJump i
                    @minimumNumberOfJumps += 1
                end
            end

                def _getIndexOfNextJump index
                    if _isNextSecondIndexInsideRange(index + 2)
                        index += _isNextSecondCloudCumulus(@cloudArray[index + 2]) ? 2 : 1
                    else
                        index += 1
                    end
                    return index
                end

                    def _isNextSecondIndexInsideRange index
                        index < @cloudArray.size
                    end

                    def _isNextSecondCloudCumulus typeOfCloud
                        typeOfCloud == 0
                    end

        def getMinimumNumberOfJumps
            @minimumNumberOfJumps
        end
    end

main
