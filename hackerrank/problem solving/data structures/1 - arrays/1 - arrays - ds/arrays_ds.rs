// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    array = reverse_array(&mut array);
    array.iter().for_each(|x| print!("{} ", x));
}

fn reverse_array(array: &mut Vec<i32>) -> Vec<i32> {
    array.reverse();
    return array.to_vec();
}
