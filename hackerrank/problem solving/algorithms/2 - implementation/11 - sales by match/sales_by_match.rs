// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

use counter::Counter;

fn main() {
    let n: usize = text_io::read!();
    let arr: Vec<i32> = read_nums(n);
    let socks_to_counts = counter(&arr);
    println!("{}", sock_merchant(&socks_to_counts));
}

fn read_nums(n: usize) -> Vec<i32> {
    (0..n).map(|_| text_io::read!()).collect()
}

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(k) extra space
fn counter(arr: &[i32]) -> Counter<i32, usize> {
    arr.iter().copied().collect::<Counter<_>>()
}

// k: length of entries in socks_to_counts
// T: O(k)
// S: O(1) extra space
fn sock_merchant(socks_to_counts: &Counter<i32>) -> usize {
    socks_to_counts.values().map(|x| x / 2).sum()
}
