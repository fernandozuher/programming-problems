# https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

def main
  gets
  birds_to_counts = counter
  puts find_most_spotted_bird(birds_to_counts)
end

# n: length of input
# k: length of distinct numbers
# T: O(n)
# S: O(n) extra space
def counter
  gets.split.each_with_object(Hash.new(0)) { |x, freq_map| freq_map[x.to_i] += 1 }
end

# n: length of input
# k: length of hash birds_to_counts
# T: O(k) = O(n)
# S: O(1) extra space
def find_most_spotted_bird(birds_to_counts)
  birds_to_counts.max_by { |bird, count| [count, -bird] }[0]
end

main if __FILE__ == $0
