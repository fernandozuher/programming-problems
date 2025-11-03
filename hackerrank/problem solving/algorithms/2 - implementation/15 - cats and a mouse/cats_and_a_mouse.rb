# https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

def main
  n = gets.to_i
  n.times { puts find_nearest_cat_or_not(read_numbers) }
end

def read_numbers
  gets.split.map(&:to_i)
end

def find_nearest_cat_or_not(positions)
  cat_a, cat_b, mouse = positions
  cat_a_from_mouse = (cat_a - mouse).abs
  cat_b_from_mouse = (cat_b - mouse).abs

  return 'Cat A' if cat_a_from_mouse < cat_b_from_mouse
  return 'Cat B' if cat_a_from_mouse > cat_b_from_mouse
  'Mouse C'
end

main if __FILE__ == $PROGRAM_NAME
