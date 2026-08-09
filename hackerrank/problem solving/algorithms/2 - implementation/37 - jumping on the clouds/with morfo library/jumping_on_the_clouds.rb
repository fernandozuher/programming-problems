# https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

require 'morfo'

def main
  Morfo.skip_input_ln
  puts min_jumps(Morfo.readln(&:to_i))
end

# n: length of clouds
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

def skip(idx, clouds) = next_second_cloud_cumulus?(idx, clouds) ? 2 : 1

def next_second_cloud_cumulus?(idx, clouds) = idx + 2 < clouds.size && clouds[idx + 2].zero?

main if __FILE__ == $0
