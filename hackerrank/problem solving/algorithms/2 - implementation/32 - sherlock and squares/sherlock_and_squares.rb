# https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

def main
  n = gets.to_i
  n.times { puts squares(read_numbers) }
end

def read_numbers
  gets.split.map(&:to_i)
end

def squares(data)
  start_num, end_num = data
  max_square = Math.sqrt(end_num).floor.to_int
  min_square = Math.sqrt(start_num).ceil.to_int
  max_square - min_square + 1
end

main if __FILE__ == $PROGRAM_NAME
