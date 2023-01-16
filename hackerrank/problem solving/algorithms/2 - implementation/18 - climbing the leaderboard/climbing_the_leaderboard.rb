#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

def main
    readLineAsIntArray
    ranked = readLineAsIntArray
    
    readLineAsIntArray
    player = readLineAsIntArray

    result = Result.new ranked, player
end

    def readLineAsIntArray
        inputLine = gets.split.map(&:to_i)
    end

    class Result

        def initialize ranked, player
            @ranked = ranked
            @player = player
            @playerRank = Array.new @player.size
            
            _removeDuplicatesFromRankedList
            _climbingLeaderboard
            printResult
        end

            def _removeDuplicatesFromRankedList
                @ranked = @ranked.uniq
            end

            def _climbingLeaderboard
                @player.each_with_index do |playerScore, i| 
                    index = _binarySearchDescendingOrder 0, @ranked.size - 1, playerScore
                    @playerRank[i] = index + 1
                end
            end

                def _binarySearchDescendingOrder low, high, key
                    if high >= low
                        middle = low + ((high - low) / 2).to_i

                        if key == @ranked[middle]
                            return middle
                        elsif key > @ranked[middle]
                            return _binarySearchDescendingOrder low, middle - 1, key
                        else
                            return _binarySearchDescendingOrder middle + 1, high, key
                        end
                    end
                    low
                end

            def printResult
                puts @playerRank
            end
    end

main
