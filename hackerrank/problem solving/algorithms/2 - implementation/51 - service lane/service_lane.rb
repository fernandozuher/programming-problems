# https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

def main
  _, n = read_int_array
  puts find_maximum_affordable_widths_vehicles_while_read_test_cases(n, read_int_array)
end

  def read_int_array
    gets.split.map(&:to_i)
  end

  def find_maximum_affordable_widths_vehicles_while_read_test_cases(n, width_measurements)
    Array.new(n).map!{maximum_affordable_width_vehicle_in_range(width_measurements, read_int_array)}
  end

    def maximum_affordable_width_vehicle_in_range(width_measurements, point)
      (width_measurements[point[0]..point[1]]).min
    end

main
