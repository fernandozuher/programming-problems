# https://www.hackerrank.com/challenges/30-more-exceptions/problem?isFullScreen=true

class RangeError < StandardError
end

def main
    calc = Calculator.new
    n_tests = gets.to_i

    n_tests.times do
        n, p = gets.split.map(&:to_i)

        begin
            puts calc.power(n, p).to_i
        rescue RangeError => e
            puts e.message
        end
    end
end

    class Calculator
        def power(n, p)
            if n < 0 || p < 0
                raise RangeError.new 'n and p should be non-negative'
            end
            n ** p
        end
    end

main
