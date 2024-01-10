// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

use std::collections::HashMap;
use text_io::read;

fn main() {
    let n: usize = read!();
    let array: Vec<i32> = read_int_array(n);
    println!("{}", sock_merchant(&array));
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn sock_merchant(socks: &Vec<i32>) -> i32 {
    let mut pairs = 0;
    let mut socks_pairing = HashMap::new();

    for sock in socks {
        if *socks_pairing.entry(sock).or_insert(false) {
            pairs += 1;
        }
        socks_pairing.insert(sock, !socks_pairing.get(sock).copied().unwrap());
    }

    return pairs;
}
