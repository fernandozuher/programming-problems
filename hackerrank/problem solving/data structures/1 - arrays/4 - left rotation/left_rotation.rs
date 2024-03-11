// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut rotate_by: usize = read!();
    let mut array: Vec<i32> = read_int_array(n);

    if rotate_by > n - 1 {
        rotate_by %= n;
    }

    array.rotate_left(rotate_by);
    print_array(&array);
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn print_array(array: &Vec<i32>) {
    for x in array {
        print!("{} ", x);
    }
}
