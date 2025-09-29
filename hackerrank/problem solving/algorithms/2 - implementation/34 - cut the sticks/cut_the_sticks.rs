// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut arr: Vec<usize> = read_numbers(n);
    arr.sort();
    for x in cut_the_sticks(&arr) {
        println!("{}", x);
    }
}

fn read_numbers(n: usize) -> Vec<usize> {
    (0..n).map(|_| read!()).collect()
}

fn cut_the_sticks(arr: &[usize]) -> Vec<usize> {
    let mut res: Vec<usize> = Vec::new();
    let mut i: usize = 0;
    let n: usize = arr.len();
    while i < n {
        res.push(n - i);
        let shortest: usize = arr[i];
        while i < n && arr[i] == shortest {
            i += 1;
        }
    }
    res
}
