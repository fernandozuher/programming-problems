# https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

def main
  gets
  arr = read_numbers
  puts min_distance(arr)
end

def read_numbers
  gets.split.map(&:to_i)
end

def min_distance(arr)
  last_seen = {}
  min_dist = nil

  arr.each_with_index do |x, i|
    if last_seen.key?(x)
      dist = i - last_seen[x]
      if min_dist == nil or dist < min_dist
        min_dist = dist
        return 1 if min_dist == 1
      end
    end
    last_seen[x] = i
  end

  min_dist || -1
end

main if __FILE__ == $PROGRAM_NAME
