# https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

def main
  gets
  puts equalize_array(read_numbers)
end

def read_numbers
  gets.split.map(&:to_i)
end

def equalize_array(arr)
  counter = arr.tally
  max_frequency = counter.values.max
  arr.length - max_frequency
end

main if __FILE__ == $PROGRAM_NAME
