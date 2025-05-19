# https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

def main
  triplet_a = read_input
  triplet_b = read_input
  score_a, score_b = compare_triplets(triplet_a, triplet_b)
  puts "#{score_a} #{score_b}"
end

def read_input
  gets.split.map(&:to_i)
end

def compare_triplets(triplet_a, triplet_b)
  score_a, score_b = 0, 0

  triplet_a.zip(triplet_b).each do |ta, tb|
    if ta > tb
      score_a += 1
    elsif tb > ta
      score_b += 1
    end
  end

  [score_a, score_b]
end

main
