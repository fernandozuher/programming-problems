#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

def main
    readLineAsIntArray
    birdSightings = readLineAsIntArray

    birdSightings = birdSightings.sort

    result = Result.new birdSightings
end

    def readLineAsIntArray
        numbers = gets.split.map(&:to_i)
    end

    class Result

        def initialize birdSightings
            @birdSightings = birdSightings
            @mostSpottedBird = nil

            birdSightings()
            printResult
        end

            private def birdSightings()
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

            def printResult
                puts @mostSpottedBird
            end
    end

main
