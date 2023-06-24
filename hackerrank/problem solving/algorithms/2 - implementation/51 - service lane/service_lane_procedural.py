# Source: https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

def main():

    _, N_TEST_CASES = read_an_int_array()
    WIDTH_MEASUREMENTS = read_an_int_array()
    MAXIMUM_AFFORDABLE_WIDTHS_VEHICLES = find_maximum_affordable_widths_vehicles_while_read_test_cases(N_TEST_CASES, WIDTH_MEASUREMENTS)
    print(*MAXIMUM_AFFORDABLE_WIDTHS_VEHICLES, sep="\n")


def read_an_int_array():

    return list(map(int, input().split()))


def find_maximum_affordable_widths_vehicles_while_read_test_cases(n_test_cases, width_measurements):

    return [maximum_affordable_width_vehicle_in_range(width_measurements, read_an_int_array()) for _ in range(n_test_cases)]


def maximum_affordable_width_vehicle_in_range(width_measurements, point):

    return min(width_measurements[point[0]:point[1]+1])


if __name__ == "__main__":
    main()
