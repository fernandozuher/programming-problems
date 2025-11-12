# https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

def main
  n = gets.to_i
  n.times do
    cycles = gets.to_i
    puts utopian_tree(cycles)
  end
end

def utopian_tree(cycles)
  (1...cycles + 1).inject(1) { |height, cycle| is_cycle_happening_during_spring(cycle) == true ? height * 2 : height + 1 }
end

def is_cycle_happening_during_spring(cycle)
  cycle.odd?
end

main if __FILE__ == $PROGRAM_NAME
