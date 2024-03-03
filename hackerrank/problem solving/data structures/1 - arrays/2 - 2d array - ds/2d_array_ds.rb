# https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

def main
    n = 6
    matrix = Array.new(n).map {gets.split.map(&:to_i)}
    puts max_hourglass_sum(matrix)
end

    def max_hourglass_sum(matrix)
        max_sum = -1 << 64
        rows_cols = 1..4

        for i in rows_cols
            for j in rows_cols
                current_sum = hourglass_sum(matrix, i, j)
                max_sum = [max_sum, current_sum].max
            end
        end

        max_sum
    end

        def hourglass_sum(matrix, i, j)
            matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1] \
                + matrix[i][j] + \
                matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1]
        end

main
