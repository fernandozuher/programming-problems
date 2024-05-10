// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n_width_measurements: usize = read!();
    let n: usize = read!();
    find_maximum_affordable_widths_vehicles_while_read_test_cases(
        n,
        read_int_array(n_width_measurements),
    )
    .iter()
    .for_each(|x| println!("{}", x));
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn find_maximum_affordable_widths_vehicles_while_read_test_cases(
    n: usize,
    width_measurements: Vec<i32>,
) -> Vec<i32> {
    let mut maximum_affordable_widths_vehicles: Vec<i32> = Vec::new();
    const TEST_CASE_SIZE: usize = 2;

    maximum_affordable_widths_vehicles.resize_with(n, || {
        maximum_affordable_width_vehicle_in_range(
            &width_measurements,
            read_int_array(TEST_CASE_SIZE),
        )
    });

    return maximum_affordable_widths_vehicles;
}

fn maximum_affordable_width_vehicle_in_range(
    width_measurements: &Vec<i32>,
    point: Vec<i32>,
) -> i32 {
    return *(&width_measurements[point[0] as usize..=point[1] as usize])
        .iter()
        .min()
        .unwrap();
}
