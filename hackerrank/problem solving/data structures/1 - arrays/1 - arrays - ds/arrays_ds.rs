// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

fn main() {
    let n: usize = text_io::read!();
    let mut arr: Vec<i32> = (0..n).map(|_| text_io::read!()).collect();
    arr.reverse();
    for x in arr.iter() {
        print!("{} ", x);
    }
}
