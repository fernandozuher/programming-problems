// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

use std::collections::HashMap;
use text_io::read;

fn main() {
    let n: usize = read!();
    let frequency: HashMap<i32, i32> = read_array_into_map(n);
    println!("{}", equalize_array(&frequency, n));
}

fn read_array_into_map(n: usize) -> HashMap<i32, i32> {
    let mut map: HashMap<i32, i32> = HashMap::new();
    for _i in 0..n {
        let x: i32 = read!();
        *map.entry(x.to_owned()).or_default() += 1;
    }
    return map;
}

fn equalize_array(array: &HashMap<i32, i32>, n: usize) -> i32 {
    let maximum_quantity_of_equal_element: i32 =
        *array.iter().max_by(|x, y| x.1.cmp(y.1)).unwrap().1;
    let minimum_number_required_deletions: i32 = n as i32 - maximum_quantity_of_equal_element;
    return minimum_number_required_deletions;
}
