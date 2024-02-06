// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

use text_io::read;

fn main() {
    let (n, mut rotation_count, n_queries): (usize, usize, usize) = (read!(), read!(), read!());
    let array: Vec<i32> = read_int_array(n);
    let queries: Vec<i32> = read_int_array(n_queries);

    rotation_count = reduce_rotations(n, rotation_count);
    let rotated_array: Vec<i32> = rotate_array(&array, rotation_count);
    print_array_according_to_index_from_another_array(&rotated_array, &queries);
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn reduce_rotations(n: usize, rotation_count: usize) -> usize {
    if n > 1 {
        return if rotation_count >= n {
            rotation_count % n
        } else {
            rotation_count
        };
    } else {
        return 0;
    }
}

fn rotate_array(array: &Vec<i32>, rotation_count: usize) -> Vec<i32> {
    let mut new_array: Vec<i32> = vec![0; array.len()];

    let mut j = 0;
    for i in (array.len() - rotation_count)..array.len() {
        new_array[j] = array[i];
        j += 1;
    }

    for i in 0..(array.len() - rotation_count) {
        new_array[j] = array[i];
        j += 1;
    }

    return new_array;
}

fn print_array_according_to_index_from_another_array(array1: &Vec<i32>, array2: &Vec<i32>) {
    array2
        .iter()
        .for_each(|i| println!("{}", array1[*i as usize]));
}
