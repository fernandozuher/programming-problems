# Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

$max_integer = 2 << 32

def main
    n_cities, _ = read_an_int_array
    cities_with_space_station = read_an_int_array
    puts find_maximum_distance_from_space_station(n_cities, cities_with_space_station)
end

    def read_an_int_array
        gets.split.map(&:to_i)
    end

    def find_maximum_distance_from_space_station(n_cities, cities_with_space_station)
        max_distance = 0
        cities_with_space_station.sort!

        for city_i in 0...n_cities
            distance = find_min_distance_between_city_and_nearest_space_station(city_i, cities_with_space_station)
            max_distance = [max_distance, distance].max
        end

        max_distance
    end

        def find_min_distance_between_city_and_nearest_space_station(city_i, cities_with_space_station)
            element = find_element_or_nearest(city_i, cities_with_space_station)
            min_distance_between_city_and_nearest_space_station = (city_i - element).abs
        end

            def find_element_or_nearest(n, array)
                max = array.length - 1
                min = 0

                min_distance = $max_integer
                nearest_element = n

                while min <= max
                    mid = ((min + max) / 2).truncate

                    distance = (array[mid] - n).abs
                    if distance < min_distance
                        nearest_element = array[mid]
                        min_distance = distance
                    end

                    if array[mid] == n
                        return n
                    elsif array[mid] > n
                        max = mid - 1
                    else
                        min = mid + 1
                    end
                end

                return nearest_element
            end

main
