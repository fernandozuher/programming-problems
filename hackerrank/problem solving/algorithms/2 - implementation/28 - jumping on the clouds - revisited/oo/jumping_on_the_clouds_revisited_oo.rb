# Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

def main
    array = readAnArray
    sizeArray = array.first
    jumpLength = array.last
    array = readAnArray

    obj = JumpingOnTheClouds.new array, jumpLength
    puts obj.getRemainingEnergy
end

    def readAnArray
        array = gets.split.map(&:to_i)
    end

    class JumpingOnTheClouds
        @array
        @jumpLength
        @energy

        def initialize array, jumpLength
            @array = array
            @jumpLength = jumpLength
            @energy = 100

            _jumpOnClouds
        end

            private def _jumpOnClouds
                cloudIndex = 0
                while true
                    @energy -= _spentEnergyAccordingToTypeOfCloud @array[cloudIndex]
                    cloudIndex = _generateNewCloudIndex cloudIndex
                    if _isCloudIndexBackToFirstCloud cloudIndex
                        break
                    end
                end
            end

                private def _spentEnergyAccordingToTypeOfCloud cloudType
                    cloudType == 0 ? 1 : 3
                end

                private def _generateNewCloudIndex cloudIndex
                    (cloudIndex + @jumpLength) % @array.size
                end

                private def _isCloudIndexBackToFirstCloud cloudIndex
                    cloudIndex == 0
                end

        def getRemainingEnergy
            @energy
        end
    end

main
