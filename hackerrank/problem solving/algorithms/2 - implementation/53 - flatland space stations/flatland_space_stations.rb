# https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

def main
  n_cities, _ = read_numbers
  last_city = n_cities - 1
  cities_with_space_station = read_numbers
  cities_with_space_station.sort!
  puts max_distance_from_space_station(last_city, cities_with_space_station)
end

def read_numbers
  gets.split.map!(&:to_i)
end

# n: length of array stations
# T: O(n)
# S: O(1) extra space
def max_distance_from_space_station(last_city, stations)
  max_dist = stations.lazy.each_cons(2).map { |prev, curr| (curr - prev).div(2) }.max || 0
  [max_dist, stations[0], last_city - stations[-1]].max
end

main if __FILE__ == $0
