#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

def main
    inputLine = readLineAsIntArray
    nTestCases = inputLine.first
    results = Array.new nTestCases

    for i in 0..(results.size - 1)
        angryProfessor = AngryProfessor.new
        results[i] = angryProfessor.getCancelledClass
    end

    for result in results
        puts result ? "YES" : "NO"
    end
end

    def readLineAsIntArray
        inputLine = gets.split.map(&:to_i)
    end

    class AngryProfessor

        def initialize
            inputLine = readLineAsIntArray
            @cancellationThreshold = inputLine.last
            @studentsArrivalTime = readLineAsIntArray

            _angryProfessor
        end

            private def _angryProfessor
               @cancelledClass = _countEarlyArrivalTime < @cancellationThreshold
            end

                private def _countEarlyArrivalTime
                    earlyArrivalTimeCount = 0

                    for studentArrivalTime in @studentsArrivalTime
                        if studentArrivalTime <= 0
                            earlyArrivalTimeCount += 1
                        end
                    end

                    earlyArrivalTimeCount
                end

        def getCancelledClass
            @cancelledClass
        end
    end

main
