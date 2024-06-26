# https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

def main
  gets
  array = read_int_array
  most_points_records, least_points_records = breaking_records(array)
  puts "#{most_points_records} #{least_points_records}"
end

  def read_int_array
    gets.split.map(&:to_i)
  end

  def breaking_records(scores)
    most_points, least_points = scores.first, scores.first
    breaking_most_points_records, breaking_least_points_records = 0, 0

    scores.each { |score|
      if score > most_points
        most_points = score
        breaking_most_points_records += 1
      elsif score < least_points
        least_points = score
        breaking_least_points_records += 1
      end
    }

    return breaking_most_points_records, breaking_least_points_records
  end

main