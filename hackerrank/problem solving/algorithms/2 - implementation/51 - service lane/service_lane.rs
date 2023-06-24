// Source: https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

use std::convert::TryFrom;
use std::io::{stdin, BufRead};

fn main() {
    let [_n_width_measurements, n_test_cases] =
        <[i32; 2]>::try_from(read_an_int_array()).ok().unwrap();

    let width_measurements: Vec<i32> = read_an_int_array();

    let maximum_affordable_widths_vehicles: Vec<i32> =
        find_maximum_affordable_widths_vehicles_while_read_test_cases(
            n_test_cases as usize,
            &width_measurements,
        );

    maximum_affordable_widths_vehicles
        .iter()
        .for_each(|element| println!("{}", element));
}

fn read_an_int_array() -> Vec<i32> {
    let array: Vec<i32> = stdin()
        .lock()
        .lines()
        .next()
        .unwrap()
        .unwrap()
        .trim()
        .split(' ')
        .map(|s| s.parse().unwrap())
        .collect();

    return array;
}

fn find_maximum_affordable_widths_vehicles_while_read_test_cases(
    n_test_cases: usize,
    width_measurements: &Vec<i32>,
) -> Vec<i32> {
    let mut maximum_affordable_widths_vehicles: Vec<i32> = Vec::with_capacity(n_test_cases);
    unsafe { maximum_affordable_widths_vehicles.set_len(n_test_cases) };

    maximum_affordable_widths_vehicles = maximum_affordable_widths_vehicles
        .iter_mut()
        .map(|_| {
            maximum_affordable_width_vehicle_in_range(&width_measurements, &read_an_int_array())
        })
        .collect();

    return maximum_affordable_widths_vehicles;
}

fn maximum_affordable_width_vehicle_in_range(
    width_measurements: &Vec<i32>,
    point: &Vec<i32>,
) -> i32 {
    let subarray = &width_measurements[point[0] as usize..=point[1] as usize];
    return *subarray.iter().min().unwrap();
}
