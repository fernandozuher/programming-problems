// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

fn main() {
    let n: usize = text_io::read!();
    let rotate_by: usize = text_io::read!();
    let mut arr: Vec<i32> = read_nums(n);
    rotate(&mut arr, rotate_by);
    for x in arr {
        print!("{} ", x);
    }
}

fn read_nums(n: usize) -> Vec<i32> {
    (0..n).map(|_| text_io::read!()).collect()
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
fn rotate(arr: &mut [i32], mut rotate_by: usize) {
    if rotate_by >= arr.len() {
        rotate_by %= arr.len();
    }
    arr.rotate_left(rotate_by);
}
