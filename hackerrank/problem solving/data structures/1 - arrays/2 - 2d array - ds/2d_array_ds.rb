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
            subrow_1_first_index = i - 1
            subrow_3_first_index = i + 1
            first_col_index = j - 1
            n = first_col_index + 3

            subrow_1_sum = matrix[subrow_1_first_index][first_col_index...n].sum
            subrow_3_sum = matrix[subrow_3_first_index][first_col_index...n].sum

            subrow_1_sum + matrix[i][j] + subrow_3_sum
        end

main
