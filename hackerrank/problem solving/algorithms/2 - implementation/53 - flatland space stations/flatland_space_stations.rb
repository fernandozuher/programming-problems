# https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

def main
  n_cities, _ = read_numbers
  last_city = n_cities - 1
  cities_with_space_station = read_numbers.sort
  puts max_distance_from_space_station(last_city, cities_with_space_station)
end

def read_numbers
  gets.split.map(&:to_i)
end

def max_distance_from_space_station(last_city, stations)
  max_dist = stations[0]

  stations.each_cons(2) do |prev, curr|
    gap = (curr - prev).div(2)
    max_dist = [max_dist, gap].max
  end

  [max_dist, last_city - stations[-1]].max

end

main if __FILE__ == $PROGRAM_NAME
