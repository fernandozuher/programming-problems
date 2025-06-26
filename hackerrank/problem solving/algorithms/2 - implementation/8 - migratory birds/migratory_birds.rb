# https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

def main
  gets
  bird_counts = count_numbers_into_hash
  puts find_most_spotted_bird(bird_counts)
end

def count_numbers_into_hash
  gets.split.each_with_object(Hash.new(0)) { |x, numberCounts| numberCounts[x.to_i] += 1 }
end

def find_most_spotted_bird(bird_counts)
  max_count = bird_counts.values.max
  bird_counts.select { |_bird, count| count == max_count }.keys.min
end

main
