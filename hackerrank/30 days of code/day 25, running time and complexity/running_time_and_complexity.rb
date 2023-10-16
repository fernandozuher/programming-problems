# https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

def main
    n = gets.to_i

    n.times do
        number = gets.to_i

        if number == 1
            puts "Not prime"
            next
        end

        i, limit = 2, Math.sqrt(number)
        while i <= limit
            if number.modulo(i).zero?
                puts "Not prime"
                break
            end
            i += 1
        end

        if i > limit
            puts "Prime"
        end
    end
end

main
