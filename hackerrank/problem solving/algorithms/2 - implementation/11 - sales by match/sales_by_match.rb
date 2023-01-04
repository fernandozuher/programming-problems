#!/bin/ruby

# Source: https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

def main
    readLineAsIntArray
    socks = readLineAsIntArray

    result = Result.new socks
end

    def readLineAsIntArray
        numbers = gets.split.map(&:to_i)
    end

    class Result

        def initialize socks
            @socks = socks
            @pairs = 0
            
            _sockMerchant
            printResult
        end

            private def _sockMerchant
                socksPairing = Hash.new

                for sock in @socks
                    if socksPairing[sock]
                        @pairs += 1
                    end
                    socksPairing[sock] = !socksPairing[sock]
                end
            end

            def printResult
                puts @pairs
            end
    end

main
