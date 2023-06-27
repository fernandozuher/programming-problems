# Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

$max_integer = 2 << 32

def main
    n_cities, _ = read_an_int_array
    cities_with_space_station = read_an_int_array
    puts find_max_distance_from_space_station(n_cities, cities_with_space_station)
end

    def read_an_int_array
        gets.split.map(&:to_i)
    end

    def find_max_distance_from_space_station(n_cities, cities_with_space_station)
        cities_with_space_station = cities_with_space_station.sort
        first_city = 0
        max_distance = cities_with_space_station.first - first_city
        previous_city = cities_with_space_station.first

        for city_with_space_station in cities_with_space_station[1...]
            distance = calculate_distance_between_cities(city_with_space_station, previous_city)
            max_distance = [max_distance, distance].max
            previous_city = city_with_space_station
        end

        last_city = n_cities-1
        last_city_with_space_station = cities_with_space_station.last
        if !has_last_city_space_station(last_city, last_city_with_space_station)
            distance = calculate_distance_of_last_city(last_city, last_city_with_space_station)
            max_distance = [max_distance, distance].max
        end

        max_distance
    end

        def calculate_distance_between_cities(city_with_space_station, previous_city)
            ((city_with_space_station - previous_city) / 2).truncate
        end

        def has_last_city_space_station(last_city, last_city_with_space_station)
            last_city == last_city_with_space_station
        end

        def calculate_distance_of_last_city(last_city, last_city_with_space_station)
            last_city - last_city_with_space_station
        end

main
