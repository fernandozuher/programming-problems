// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

use std::cmp;
use text_io::read;

fn main() {
    let n: usize = read!();
    let mut array: Vec<i32> = read_int_array(n);
    array.sort();
    println!("{}", picking_numbers(&array));
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn picking_numbers(numbers: &Vec<i32>) -> usize {
    let mut subarray_biggest_size: usize = 0;
    let mut first_reference_number_index: usize = 0;
    let mut second_reference_number_index: usize = 0;
    let mut subarray_current_size: usize = 1;

    for i in 1..numbers.len() {
        let difference: i32 = numbers[i] - numbers[first_reference_number_index];

        match difference {
            0 => subarray_current_size += 1,
            1 => {
                subarray_current_size += 1;
                if numbers[second_reference_number_index] != numbers[i] {
                    second_reference_number_index = i;
                }
            }
            _ => {
                subarray_biggest_size =
                    update_subarray_biggest_size(subarray_biggest_size, subarray_current_size);

                let update: Vec<usize> =
                    update_first_reference_number_index_and_subarray_current_size(
                        numbers,
                        i,
                        second_reference_number_index,
                    );

                first_reference_number_index = *update.first().unwrap();
                second_reference_number_index = i;
                subarray_current_size = *update.last().unwrap();
            }
        }
    }

    return update_subarray_biggest_size(subarray_biggest_size, subarray_current_size);
}

fn update_subarray_biggest_size(
    subarray_biggest_size: usize,
    subarray_current_size: usize,
) -> usize {
    return cmp::max(subarray_biggest_size, subarray_current_size);
}

fn update_first_reference_number_index_and_subarray_current_size(
    numbers: &Vec<i32>,
    i: usize,
    second_reference_number_index: usize,
) -> Vec<usize> {
    let (first_reference_number_index, subarray_current_size): (usize, usize);

    if numbers[i] - numbers[second_reference_number_index] == 1 {
        first_reference_number_index = second_reference_number_index;
        subarray_current_size = i - second_reference_number_index + 1;
    } else {
        first_reference_number_index = i;
        subarray_current_size = 1;
    }

    return vec![first_reference_number_index, subarray_current_size];
}
