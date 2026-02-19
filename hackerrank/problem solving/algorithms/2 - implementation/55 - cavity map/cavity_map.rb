# https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

def main
  n = gets.to_i
  matrix = Array.new(n) { gets.chomp }
  change_matrix_to_cavity_map(matrix)
  puts matrix
end

# n: length of rows/cols of matrix
# T: O(n^2)
# S: O(1) extra space
def change_matrix_to_cavity_map(matrix)
  range = (1...matrix.length - 1)
  range.each do |i|
    range.each do |j|
      matrix[i][j] = 'X' if is_cell_cavity(matrix, i, j)
    end
  end
end

def is_cell_cavity(matrix, i, j)
  c = matrix[i][j]
  matrix[i - 1][j] < c &&
    matrix[i][j - 1] < c &&
    matrix[i + 1][j] < c &&
    matrix[i][j + 1] < c
end

main if __FILE__ == $0
