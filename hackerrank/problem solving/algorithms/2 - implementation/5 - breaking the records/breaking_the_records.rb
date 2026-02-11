# https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

def main
  gets
  puts breaking_records(read_numbers).join(' ')
end

def read_numbers
  gets.split.map!(&:to_i)
end

def breaking_records(scores)
  most_points, least_points = scores.first, scores.first
  most_record_breaks, least_record_breaks = 0, 0

  scores[1..].each do |score|
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
