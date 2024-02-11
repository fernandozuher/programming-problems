# https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

def main
    number = gets.to_i
    factorial = calculate_factorial_of(number)
    puts factorial
end

    def calculate_factorial_of(number)
        factorial = 1
        for current_number in 2..number
            factorial *= current_number
        end
        factorial
    end

main
