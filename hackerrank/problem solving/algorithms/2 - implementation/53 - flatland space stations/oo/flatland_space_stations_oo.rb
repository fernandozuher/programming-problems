# Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

$max_integer = 2 << 32

def main
    n_cities, _ = read_an_int_array
    cities_with_space_station = read_an_int_array
    obj = FlatlandSpaceStations.new(n_cities, cities_with_space_station)
    puts obj.get_max_distance_from_space_station
end

    def read_an_int_array
        gets.split.map(&:to_i)
    end

    class FlatlandSpaceStations
        @n_cities
        @cities_with_space_station
        @max_distance_from_space_station

        def initialize(n_cities, cities_with_space_station)
            @n_cities = n_cities
            @cities_with_space_station = cities_with_space_station
            @max_distance_from_space_station = 0

            @cities_with_space_station = @cities_with_space_station.sort
            self.find_max_distance_from_space_station
        end

            private def find_max_distance_from_space_station
                first_city = 0
                @max_distance_from_space_station = @cities_with_space_station.first - first_city
                previous_city = @cities_with_space_station.first

                for city_with_space_station in @cities_with_space_station[1...]
                    distance = self.calculate_distance_between_cities(city_with_space_station, previous_city)
                    @max_distance_from_space_station = [@max_distance_from_space_station, distance].max
                    previous_city = city_with_space_station
                end

                if !self.has_last_city_space_station
                    distance = self.calculate_distance_of_last_city
                    @max_distance_from_space_station = [@max_distance_from_space_station, distance].max
                end
            end

                private def calculate_distance_between_cities(city_with_space_station, previous_city)
                    ((city_with_space_station - previous_city) / 2).truncate
                end

                private def has_last_city_space_station
                    @n_cities-1 == @cities_with_space_station.last
                end

                private def calculate_distance_of_last_city
                    @n_cities-1 - @cities_with_space_station.last
                end

        def get_max_distance_from_space_station
            @max_distance_from_space_station
        end
    end

main
