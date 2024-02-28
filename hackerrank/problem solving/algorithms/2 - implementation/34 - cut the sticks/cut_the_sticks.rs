// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut array: Vec<usize> = read_int_array(n);
    array.sort();
    print_array(&cut_the_sticks(&mut array));
}

fn read_int_array(n: usize) -> Vec<usize> {
    let mut array: Vec<usize> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn cut_the_sticks(mut array: &mut Vec<usize>) -> Vec<usize> {
    let n: usize = array.len();
    let mut remaining_sticks_of_each_iteration: Vec<usize> = vec![n; 1];

    let mut i = 0;
    while i < n {
        let shortest_stick_length: usize = array[i];

        i = find_first_element_index_different_of_first_current_shortest_stick_length_index(
            i, array,
        );

        let current_iterationn: usize = n - i;
        if i == n {
            break;
        }

        remaining_sticks_of_each_iteration.push(current_iterationn);
        array = decrease_sticks_lengths_higher_than_current_shortest_stick_length(
            i,
            array,
            shortest_stick_length,
        );
    }

    return remaining_sticks_of_each_iteration;
}

fn find_first_element_index_different_of_first_current_shortest_stick_length_index(
    mut index: usize,
    array: &Vec<usize>,
) -> usize {
    let n: usize = array.len();
    let shortest_stick_length: usize = array[index];

    while index < n && array[index] == shortest_stick_length {
        index += 1;
    }

    return index;
}

fn decrease_sticks_lengths_higher_than_current_shortest_stick_length(
    index: usize,
    array: &mut Vec<usize>,
    shortest_stick_length: usize,
) -> &mut Vec<usize> {
    for i in index..array.len() {
        array[i] -= shortest_stick_length;
    }
    return array;
}

fn print_array(array: &Vec<usize>) {
    array.iter().for_each(|x| println!("{}", x));
}
