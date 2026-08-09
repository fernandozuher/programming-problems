# https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

require 'morfo'

def main
  n_cities, _ = Morfo.readln(&:to_i)
  last_city = n_cities - 1
  cities_with_space_station = Morfo.readln(&:to_i)
  cities_with_space_station.sort!
  puts max_distance_from_space_station(last_city, cities_with_space_station)
end

# n: length of stations
# T: O(n)
# S: O(1) extra space
def max_distance_from_space_station(last_city, stations)
  max_dist = stations.lazy.each_cons(2).map { |prev, curr| (curr - prev).div(2) }.max || 0
  [max_dist, stations[0], last_city - stations[-1]].max
end

main if __FILE__ == $0
