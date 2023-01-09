#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

def main
    inputLine = readLineAsIntArray
    budget = inputLine.first
    keyboardCosts = readLineAsIntArray
    usbDriveCosts = readLineAsIntArray

    keyboardCosts = keyboardCosts.sort
    usbDriveCosts = usbDriveCosts.sort

    result = Result.new keyboardCosts, usbDriveCosts, budget
end

    def readLineAsIntArray
        inputLine = gets.split.map(&:to_i)
    end

    class Result

        def initialize keyboardCosts, usbDriveCosts, budget
            @keyboardCosts = keyboardCosts
            @usbDriveCosts = usbDriveCosts
            @budget = budget
            @canBeSpent = 0

            _getMoneySpent
            printResult
        end

            private def _getMoneySpent
                @keyboardCosts.each_index { |i|

                    if _isNextCostEqualToCurrentOne @keyboardCosts, i
                        next
                    end

                    @usbDriveCosts.each_index { |j|

                        if _isNextCostEqualToCurrentOne @usbDriveCosts, j
                            next
                        end

                        sum = @keyboardCosts[i] + @usbDriveCosts[j]

                        if _isSumInsideBudget sum
                            @canBeSpent = _updateCost sum
                        else
                            break
                        end
                    }

                    @canBeSpent = @canBeSpent > 0 ? @canBeSpent : -1
                }
            end

                def _isNextCostEqualToCurrentOne deviceCosts, currentIndex
                    return currentIndex < deviceCosts.size - 1 && deviceCosts[currentIndex] == deviceCosts[currentIndex + 1]
                end

                def _isSumInsideBudget sum
                    return sum <= @budget
                end

                def _updateCost sum
                    return [sum, @canBeSpent].max
                end

            def printResult
                puts @canBeSpent
            end
    end

main
