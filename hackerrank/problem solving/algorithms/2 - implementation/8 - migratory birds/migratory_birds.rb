# https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

def main
    n = gets.to_i
    array = readIntArray
    array.sort!

    obj = MigratoryBirds.new(array)
    puts obj.mostSpottedBird
end

    def readIntArray
        gets.split.map(&:to_i)
    end

    class MigratoryBirds
        attr_reader :mostSpottedBird

        def initialize(birdSightings)
            @birdSightings = birdSightings
            @mostSpottedBird = nil
            findMostSpottedBird
        end

            private def findMostSpottedBird
                @mostSpottedBird = @birdSightings.first
                countMostSpottedBird = 1
                tempCountMostSpottedBird = 1

                for i in 1..(@birdSightings.size - 1)

                    if @birdSightings[i] == @birdSightings[i - 1]
                        tempCountMostSpottedBird += 1

                    elsif tempCountMostSpottedBird > countMostSpottedBird
                        @mostSpottedBird = @birdSightings[i - 1]
                        countMostSpottedBird = tempCountMostSpottedBird
                        tempCountMostSpottedBird = 1
                    end
                end

                if tempCountMostSpottedBird > countMostSpottedBird
                    @mostSpottedBird = @birdSightings.last
                end
            end
    end

main
