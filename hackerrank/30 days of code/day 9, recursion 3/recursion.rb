# https://www.hackerrank.com/challenges/30-recursion/problem?isFullScreen=true

def main
    n = gets.to_i
    puts factorial(n)
end

    def factorial(n)
        n == 1 ? 1 : n * factorial(n - 1)
    end

main
