# https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

def main
  n = gets.to_i
  utopian_tree = generate_heights_utopian_tree
  n.times do
    cycles = gets.to_i
    puts utopian_tree[cycles]
  end
end

# k: length of output = 61
# T: O(k) = O(61) = O(1)
# S: O(61) = O(1) extra space
def generate_heights_utopian_tree
  max_cycles = 60
  height = 0
  0.upto(max_cycles).map { height += cycle_happening_during_spring?(_1) ? height : 1 }
end

def cycle_happening_during_spring?(cycle)
  cycle.odd?
end

main if __FILE__ == $0
