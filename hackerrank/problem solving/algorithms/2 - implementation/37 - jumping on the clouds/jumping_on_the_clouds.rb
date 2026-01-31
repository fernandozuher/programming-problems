# https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

def main
  gets
  puts min_jumps(read_numbers)
end

def read_numbers
  gets&.split&.map!(&:to_i)
end

# n: length of array clouds
# T: O(n)
# S: O(1) extra space
def min_jumps(clouds)
  i = 0
  n = clouds.size - 1
  jumps = 0

  while i < n
    i += skip(i, clouds)
    jumps += 1
  end
  jumps
end

def skip(idx, clouds)
  is_next_second_cloud_cumulus(idx, clouds) ? 2 : 1
end

def is_next_second_cloud_cumulus(idx, clouds)
  idx + 2 < clouds.size && clouds[idx + 2] == 0
end

main if __FILE__ == $0
