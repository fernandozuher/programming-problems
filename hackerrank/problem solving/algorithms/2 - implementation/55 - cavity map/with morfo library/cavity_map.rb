# https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

require 'morfo'

def main
  n = Morfo.read(&:to_i)
  matrix = Array.new(n) { Morfo.read(&:to_s) }
  change_matrix_to_cavity_map(matrix)
  puts matrix
end

# n: length of matrix' rows
# T: O(n^2)
# S: O(1) extra space
def change_matrix_to_cavity_map(matrix)
  range = (1...matrix.length - 1)
  range.each do |i|
    range.each do |j|
      matrix[i][j] = 'X' if cavity_cell?(matrix, i, j)
    end
  end
end

def cavity_cell?(matrix, i, j)
  c = matrix[i][j]
  matrix[i - 1][j] < c &&
    matrix[i][j - 1] < c &&
    matrix[i + 1][j] < c &&
    matrix[i][j + 1] < c
end

main if __FILE__ == $0
