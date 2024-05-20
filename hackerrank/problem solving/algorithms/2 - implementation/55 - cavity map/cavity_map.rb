# https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

def main
  n_rows_columns = gets.to_i
  matrix = Array.new(n_rows_columns) { gets.chomp }
  change_matrix_to_cavity_map(matrix)
  puts matrix
end

  def change_matrix_to_cavity_map(matrix)
    cavity = 'X'
    range = 1...(matrix.size - 1)
    range.each { |i|
      range.each { |j|
        if is_cell_cavity?(matrix, i, j)
          matrix[i][j] = cavity
        end
      }
    }
  end

    def is_cell_cavity?(matrix, i, j)
      matrix[i - 1][j] < matrix[i][j] \
        && matrix[i][j - 1] < matrix[i][j] \
        && matrix[i + 1][j] < matrix[i][j] \
        && matrix[i][j + 1] < matrix[i][j]
    end

main
