# https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

def main
  _, max_jump = read_numbers
  hurdles = read_numbers
  puts hurdle_race(hurdles, max_jump)
end

def read_numbers
  gets.split.map(&:to_i)
end

def hurdle_race(hurdles, max_jump)
  [0, hurdles.max - max_jump].max
end

main if __FILE__ == $PROGRAM_NAME
