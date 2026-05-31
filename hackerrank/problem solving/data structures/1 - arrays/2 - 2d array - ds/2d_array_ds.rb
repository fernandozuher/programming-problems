# https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

def main
  n = 6
  matrix = n.times.map { read_numbers }
  puts max_hourglass_sum(matrix)
end

def read_numbers
  gets.split.map!(&:to_i)
end

# T: O(1)
# S: O(1) extra space
def max_hourglass_sum(matrix)
  max_sum = -1 << 64
  rows_cols = 1..4

  rows_cols.each { |i|
    rows_cols.each { |j|
      current_sum = hourglass_sum(matrix, i, j)
      max_sum = [max_sum, current_sum].max
    }
  }

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

main if __FILE__ == $0
