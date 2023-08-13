# https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

def main
    matrix = read_matrix
    max_sum = calculate_max_sum(matrix)
    puts max_sum
end

    def read_matrix
        n_rows_columns = 6
        matrix = Array.new(n_rows_columns).map{gets.split.map(&:to_i)}
    end

    def calculate_max_sum(matrix)
        max_sum = -1 << 32
        before_rows_columns_limit = 5

        for i in 1...before_rows_columns_limit
            for j in 1...before_rows_columns_limit
                max_sum = [max_sum, sum_around(matrix, i, j)].max
            end
        end

        max_sum
    end

        def sum_around(matrix, i, j)
            matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1] +
                matrix[i][j] +
                matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1]
        end

main
