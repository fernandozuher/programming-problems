# https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

require 'morfo'

def main
  Morfo.skip_input_ln
  puts breaking_records(Morfo.readln(&:to_i)).join(' ')
end

# n: length of scores
# T: O(n)
# S: O(1) extra space
def breaking_records(scores)
  most_points, least_points = scores.first, scores.first
  most_record_breaks, least_record_breaks = 0, 0

  scores.each do |score|
    if score > most_points
      most_points = score
      most_record_breaks += 1
    elsif score < least_points
      least_points = score
      least_record_breaks += 1
    end
  end

  [most_record_breaks, least_record_breaks]
end

main if __FILE__ == $0
