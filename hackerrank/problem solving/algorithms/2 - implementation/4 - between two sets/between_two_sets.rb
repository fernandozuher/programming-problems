#!/bin/ruby

class Result

    def initialize setA, setB
        @setA = setA
        @setB = setB
        @potentialFactors = Array.new

        findFactors
        printResult
    end

        private def findFactors
            findNumbersDivisibleBySetA
            findFactorsOfSetB
            countFactors
        end
        
            private def findNumbersDivisibleBySetA
                for potentialFactor in (@setA.last..@setB.first).step(@setA.last)
                    @isARealPotentialFactor = true

                    for elementA in @setA
                        if (potentialFactor % elementA) != 0
                            @isARealPotentialFactor = false
                            break
                        end
                    end

                    if @isARealPotentialFactor == true
                        @potentialFactors.push(potentialFactor)
                    end
                end
            end

            private def findFactorsOfSetB
                for elementB in @setB
                    @potentialFactors.each_with_index { |potentialFactor, i|
                        if potentialFactor != 0 && (elementB % potentialFactor) != 0
                            @potentialFactors[i] = 0
                        end
                    }
                end
            end

            private def countFactors
                @totalFactors = @potentialFactors.reduce(0) { |previousResult, item|
                    item != 0 ? (previousResult + 1) : previousResult
                }
            end

        def printResult
            puts "#{@totalFactors}"
        end
end

def readLineAsIntArray
    numbers = gets.split.map(&:to_i)
end

def main
    readLineAsIntArray
    setA = readLineAsIntArray
    setB = readLineAsIntArray

    setA = setA.sort
    setB = setB.sort

    result = Result.new(setA, setB)
end

main