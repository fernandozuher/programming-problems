#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true 

def main
    readLineAsIntArray
    steps = readLineAsString

    result = Result.new steps
end

    def readLineAsIntArray
        inputLine = gets.split.map(&:to_i)
    end

    def readLineAsString
        inputLine = gets
    end

    class Result

        def initialize steps
            @steps = steps
            @traversedValleys = 0

            _countingValleys
            printResult
        end

            private def _countingValleys
                currentAltitude = 0

                for step in @steps.split("")
                    wasTravessingAValley = currentAltitude < 0
                    currentAltitude += step == 'D' ? -1 : 1
                    
                    if _isInSeaLevelFromValley wasTravessingAValley, currentAltitude
                        @traversedValleys += 1
                    end
                end
            end

            private def _isInSeaLevelFromValley wasTravessingAValley, currentAltitude
                wasTravessingAValley && currentAltitude == 0
            end

            def printResult
                puts @traversedValleys
            end
    end

main
