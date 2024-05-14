# https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

def main
  n_cities, _ = read_int_array
  cities_with_space_station = read_int_array
  cities_with_space_station.sort!
  p find_max_distance_from_space_station(n_cities, cities_with_space_station)
end

  def read_int_array
    gets.split.map(&:to_i)
  end

  def find_max_distance_from_space_station(n_cities, cities_with_space_station)
    max_distance_from_space_station = previous_city = cities_with_space_station.first

    cities_with_space_station[1..].each { |city_with_space_station|
      distance_between_cities = ((city_with_space_station - previous_city) / 2).truncate
      max_distance_from_space_station = [max_distance_from_space_station, distance_between_cities].max
      previous_city = city_with_space_station
    }

    unless (has_last_city_space_station = n_cities - 1 == cities_with_space_station.last)
      distance_of_last_city = n_cities - 1 - cities_with_space_station.last
      max_distance_from_space_station = [max_distance_from_space_station, distance_of_last_city].max
    end

    max_distance_from_space_station
  end

main
