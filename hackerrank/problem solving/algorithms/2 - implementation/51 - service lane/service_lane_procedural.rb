# Source: https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

def main()
    _, n_test_cases = read_an_int_array
    width_measurements = read_an_int_array
    maximum_affordable_widths_vehicles = find_maximum_affordable_widths_vehicles_while_read_test_cases(n_test_cases, width_measurements)
    puts maximum_affordable_widths_vehicles
end

    def read_an_int_array
        gets.split.map(&:to_i)
    end

    def find_maximum_affordable_widths_vehicles_while_read_test_cases(n_test_cases, width_measurements)
        Array.new(n_test_cases).map!{maximum_affordable_width_vehicle_in_range(width_measurements, read_an_int_array)}
    end

        def maximum_affordable_width_vehicle_in_range(width_measurements, point)
            (width_measurements[point[0]..point[1]]).min
        end

main
