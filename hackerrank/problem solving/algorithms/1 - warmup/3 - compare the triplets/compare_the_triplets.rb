# https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

def main
  triplet_a = read_nums
  triplet_b = read_nums
  score_a, score_b = compare_triplets(triplet_a, triplet_b)
  puts "#{score_a} #{score_b}"
end

def read_nums
  gets.split.map!(&:to_i)
end

# n: length of a and b = 3
# T: O(3) => O(1)
# S: O(1) extra space
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

main if __FILE__ == $0
