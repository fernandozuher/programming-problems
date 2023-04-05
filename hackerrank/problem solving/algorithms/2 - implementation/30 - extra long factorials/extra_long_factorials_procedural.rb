# Source: https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

def main
    number = gets.to_i
    factorial = calculateFactorialOf number
    puts factorial
end

    def calculateFactorialOf number
        factorial = 1
        for i in 2..number
            factorial *= i
        end
        factorial
    end

main
