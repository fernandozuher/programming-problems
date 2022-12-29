#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

class Result

    def initialize setA
        @scores = setA
        @breakingMostPointsRecords = 0
    	@breakingLeastPointsRecords = 0
        breakingRecords
        printResult
    end

        private def breakingRecords
            mostPoints = @scores.first
	        leastPoints = @scores.first

	        for score in @scores
	            if score > mostPoints 
	                mostPoints = score
	                @breakingMostPointsRecords += 1
	            elsif score < leastPoints
	                leastPoints = score
	                @breakingLeastPointsRecords += 1
	            end
	        end
        end

        def printResult
            puts "#{@breakingMostPointsRecords} #{@breakingLeastPointsRecords}"
        end
end

def readLineAsIntArray
    numbers = gets.split.map(&:to_i)
end

def main
    readLineAsIntArray
    setA = readLineAsIntArray

    result = Result.new setA
end

main
