# https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

def main
    n = gets.to_i
    staircase(n)
end

    def staircase(n)
        for i in 1..n
            (0..n-i-1).each do
                print ' '
            end
            (0..i-1).each do
                print '#'
            end
            puts ''
        end
    end

main