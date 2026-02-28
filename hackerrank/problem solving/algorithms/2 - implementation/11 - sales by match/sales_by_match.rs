// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

use counter::Counter;
use text_io::read;

fn main() {
    let n: usize = read!();
    let socks_to_counts: Counter<i32, i32> = counter(n);
    println!("{}", sock_merchant(&socks_to_counts));
}

// n: length of user input
// k: length of distinct numbers in user input
// k <= n
// T: O(n)
// S: O(k) extra space
fn counter(n: usize) -> Counter<i32, i32> {
    let mut freq_map = Counter::<i32, i32>::new();
    for _ in 0..n {
        freq_map[&read!()] += 1;
    }
    freq_map
}

// n: length of initial user input
// k: length of entries in socks_to_counts
// k <= n
// T: O(k)
// S: O(1) extra space
fn sock_merchant(socks_to_counts: &Counter<i32, i32>) -> i32 {
    socks_to_counts.values().map(|x| x / 2).sum()
}
