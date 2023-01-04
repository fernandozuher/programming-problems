#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

def main
    input1 = readLineAsIntArray
    itemAnnaDidntConsume = input1.last
    
    costOfEachMeal = readLineAsIntArray
    brianChargedAnna = readLineAsIntArray

    result = Result.new costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna.first
end

    def readLineAsIntArray
        numbers = gets.split.map(&:to_i)
    end

    class Result

        def initialize costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna
            @costOfEachMeal = costOfEachMeal
            @itemAnnaDidntConsume = itemAnnaDidntConsume
            @brianChargedAnna = brianChargedAnna
            @brianOverchargedAnna = ""

            _bonAppetit
            printResult
        end

            private def _bonAppetit
                annaCost = _calculateAnnaCost
                _checkIfBrianOverchargedAnna annaCost
            end

                private def _calculateAnnaCost
                    sum = @costOfEachMeal.sum
                    annaCost = (sum - @costOfEachMeal[@itemAnnaDidntConsume]) / 2
                    return annaCost
                end

                private def _checkIfBrianOverchargedAnna annaCost
                    if annaCost == @brianChargedAnna
                        @brianOverchargedAnna = "Bon Appetit"
                    else
                        brianOverchargedAnna = @brianChargedAnna - annaCost
                        @brianOverchargedAnna = brianOverchargedAnna.to_s
                    end
                end

            def printResult
                puts @brianOverchargedAnna
            end
    end

main
