// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let array: Vec<i32> = read_int_array(n);
    print_array(&permutation_equation(&array));
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn permutation_equation(array: &Vec<i32>) -> Vec<i32> {
    let elements_positions_array: Vec<i32> = generate_elements_positions_array(array);
    return generate_permutated_array(&elements_positions_array);
}

fn generate_elements_positions_array(array: &Vec<i32>) -> Vec<i32> {
    let mut elements_positions_array: Vec<i32> = vec![0; array.len()];
    for (i, element) in array.iter().enumerate() {
        elements_positions_array[*element as usize - 1] = i as i32;
    }
    return elements_positions_array;
}

fn generate_permutated_array(array: &Vec<i32>) -> Vec<i32> {
    let mut permutated_array: Vec<i32> = vec![0; array.len()];
    for (i, element) in array.iter().enumerate() {
        permutated_array[i] = array[*element as usize] + 1;
    }
    return permutated_array;
}

fn print_array(array: &Vec<i32>) {
    array.iter().for_each(|x| println!("{}", x));
}
