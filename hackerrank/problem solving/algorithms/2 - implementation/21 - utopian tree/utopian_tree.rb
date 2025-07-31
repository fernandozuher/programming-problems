# https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

def main
  n = gets.to_i
  test_cases = read_numbers(n)
  puts utopian_tree(test_cases)
end

def read_numbers(n)
  Array.new(n) { gets.to_i }
end

def utopian_tree(test_cases)
  test_cases.map { |cycles| calculate_height(cycles) }
end

def calculate_height(cycles)
  (1...cycles + 1).inject(1) { |height, cycle| is_cycle_happening_during_spring(cycle) == true ? height * 2 : height + 1 }
end

def is_cycle_happening_during_spring(cycle)
  cycle.odd?
end

main if __FILE__ == $PROGRAM_NAME
