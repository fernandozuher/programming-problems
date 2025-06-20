# https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

def main
  gets
  birds = read_numbers
  puts find_most_spotted_bird(birds)
end

def read_numbers
  gets.split.map(&:to_i)
end

def find_most_spotted_bird(birds)
  bird_count = birds.each_with_object(Hash.new(0)) { |bird, counts| counts[bird] += 1 }
  max_count = bird_count.values.max
  bird_count.select { |_bird, count| count == max_count }.keys.min
end

main
