# https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

def main
  n = gets.to_i
  matrix = Array.new(n) { gets.chomp }
  change_matrix_to_cavity_map(matrix)
  puts matrix
end

def change_matrix_to_cavity_map(matrix)
  range = 1...(matrix.size - 1)
  range.each do |i|
    range.each do |j|
      if is_cell_cavity?(matrix, i, j)
        matrix[i][j] = 'X'
      end
    end
  end
end

def is_cell_cavity?(matrix, i, j)
  matrix[i - 1][j] < matrix[i][j] &&
    matrix[i][j - 1] < matrix[i][j] &&
    matrix[i + 1][j] < matrix[i][j] &&
    matrix[i][j + 1] < matrix[i][j]
end

main if __FILE__ == $PROGRAM_NAME
