# https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

def main
    n, rotate_by = read_int_array
    array = read_int_array

    if rotate_by > n - 1
        rotate_by %= n
    end

    array.rotate!(rotate_by)
    puts array.join(' ')
end

    def read_int_array
        gets.split.map(&:to_i)
    end

main
