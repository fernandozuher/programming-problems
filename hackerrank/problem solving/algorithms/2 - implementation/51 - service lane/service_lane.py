# https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

def main():
    _, n = read_int_array()
    print(*find_maximum_affordable_widths_vehicles_while_read_test_cases(n, read_int_array()), sep='\n')


def read_int_array():
    return list(map(int, input().split()))


def find_maximum_affordable_widths_vehicles_while_read_test_cases(n, width_measurements):
    return [maximum_affordable_width_vehicle_in_range(width_measurements, read_int_array()) for _ in range(n)]


def maximum_affordable_width_vehicle_in_range(width_measurements, point):
    return min(width_measurements[point[0]:point[1] + 1])


if __name__ == '__main__':
    main()
