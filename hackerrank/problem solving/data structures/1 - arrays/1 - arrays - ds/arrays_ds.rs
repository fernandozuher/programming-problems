// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut arr: Vec<i32> = (0..n).map(|_| read!()).collect();
    arr.reverse();
    for x in arr.iter() {
        print!("{} ", x);
    }
}
