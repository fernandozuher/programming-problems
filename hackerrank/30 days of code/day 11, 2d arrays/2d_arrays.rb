# https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

def main
  matrix = read_matrix
  puts calculate_max_sum(matrix)
end

def read_matrix
  n_rows_columns = 6
  Array.new(n_rows_columns).map { gets.split.map(&:to_i) }
end

def calculate_max_sum(matrix)
  max_sum = -1 << 32
  before_rows_columns_limit = 5

  (1...before_rows_columns_limit).each { |i|
    (1...before_rows_columns_limit).each { |j|
      max_sum = [max_sum, sum_around(matrix, i, j)].max
    }
  }

  max_sum
end

def sum_around(matrix, i, j)
  matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1] +
    matrix[i][j] +
    matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1]
end

main
