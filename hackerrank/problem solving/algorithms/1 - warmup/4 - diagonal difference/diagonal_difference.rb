# https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

def main
    n = gets.to_i
    matrix = read_matrix(n)
    puts diagonal_difference(matrix)
end

    def read_matrix(n)
        matrix = Array.new(n)
        n.times do |i|
            matrix[i] = gets.split.map(&:to_i)
        end
        matrix
    end

    def diagonal_difference(matrix)
        primary_diagonal, secondary_diagonal = 0, 0
        j = matrix.size - 1

        matrix.each_index do |i|
            primary_diagonal += matrix[j][j]
            secondary_diagonal += matrix[j][i]
            j -= 1
        end

        (primary_diagonal - secondary_diagonal).abs
    end

main
