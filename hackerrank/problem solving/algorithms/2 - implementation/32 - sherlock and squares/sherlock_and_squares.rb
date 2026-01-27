# https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

def main
  n = gets.to_i
  n.times do
    a, b = read_numbers
    puts squares(a, b)
  end
end

def read_numbers
  gets&.split&.map!(&:to_i)
end

# T: O(1)
# S: O(1) extra space
def squares(start_num, end_num)
  max_square = Math.sqrt(end_num).floor.to_i
  min_square = Math.sqrt(start_num).ceil.to_i
  max_square - min_square + 1
end

main if __FILE__ == $0
