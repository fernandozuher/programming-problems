# https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

def main
  birds_to_counts = read_input
  puts find_most_spotted_bird(birds_to_counts)
end

# n: length of input
# T: O(n)
# S: O(n) extra space
def read_input
  gets
  gets.split.map!(&:to_i).tally
end

# n: length of birds_to_counts
# T: O(n)
# S: O(1) extra space
def find_most_spotted_bird(birds_to_counts)
  id, _ = birds_to_counts.max_by { |id, count| [count, -id] }
  id
end

main if __FILE__ == $0
