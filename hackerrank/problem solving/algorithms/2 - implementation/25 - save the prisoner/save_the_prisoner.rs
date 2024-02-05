// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut prisoners_chair_number_to_warn: Vec<i32> = vec![0; n];

    for i in 0..n {
        let prisoners: i32 = read!();
        let sweets: i32 = read!();
        let chair_number_to_begin: i32 = read!();
        prisoners_chair_number_to_warn[i] =
            save_the_prisoner(prisoners, sweets, chair_number_to_begin);
    }

    print_array(prisoners_chair_number_to_warn);
}

fn save_the_prisoner(prisoners: i32, sweets: i32, chair_number_to_begin: i32) -> i32 {
    let prisoner_chair_number_to_warn: i32 = chair_number_to_begin + (sweets - 1);
    let mut x: i32 = prisoner_chair_number_to_warn;

    if x > prisoners {
        x %= prisoners;
        if x == 0 {
            x = prisoners;
        }
    }

    return x;
}

fn print_array(array: Vec<i32>) {
    array.iter().for_each(|x| println!("{}", x));
}
