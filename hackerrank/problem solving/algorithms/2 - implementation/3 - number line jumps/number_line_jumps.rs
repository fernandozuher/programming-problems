// Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

use text_io::read;

fn main() {
    const SIZE: usize = 4;
    let array: Vec<i32> = read_int_array(SIZE);
    println!("{}", kangaroo(array));
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn kangaroo(array: Vec<i32>) -> String {
    let mut x1: i32 = array[0];
    let v1: i32 = array[1];
    let mut x2: i32 = array[2];
    let v2: i32 = array[3];

    if v2 >= v1 {
        return "NO".to_string();
    }

    while x1 < x2 {
        x1 += v1;
        x2 += v2;
    }

    if x1 == x2 {
        return "YES".to_string();
    } else {
        return "NO".to_string();
    }
}
