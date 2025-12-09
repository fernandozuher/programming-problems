# https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

def main
  gets
  puts minimum_number_of_jumps(read_numbers)
end

def read_numbers
  gets.split.map(&:to_i)
end

def minimum_number_of_jumps(clouds)
  i = 0
  n = clouds.size - 1
  jumps = 0

  while i < n
    i += next_jump(i, clouds)
    jumps += 1
  end
  jumps
end

def next_jump(index, clouds)
  if index + 2 < clouds.size
    if (is_next_second_cloud_cumulus = clouds[index + 2] == 0)
      return 2
    end
  end
  1
end

main if __FILE__ == $PROGRAM_NAME
