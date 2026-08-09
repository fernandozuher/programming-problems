# https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

require 'morfo'

def main
  n = Morfo.read(&:to_i)
  n.times { puts find_nearest_cat_or_not(Morfo.readln(&:to_i)) }
end

# T: O(1)
# S: O(1) extra space
def find_nearest_cat_or_not(positions)
  cat_a, cat_b, mouse = positions
  cat_a_from_mouse = (cat_a - mouse).abs
  cat_b_from_mouse = (cat_b - mouse).abs

  return 'Cat A' if cat_a_from_mouse < cat_b_from_mouse
  return 'Cat B' if cat_a_from_mouse > cat_b_from_mouse
  'Mouse C'
end

main if __FILE__ == $0
