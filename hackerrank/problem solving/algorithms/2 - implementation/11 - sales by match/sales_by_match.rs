// Source: https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

use std::io::{self, BufRead};
use std::collections::HashMap;

fn main() {
    read_line_as_vec_i32();
    let socks = read_line_as_vec_i32();

    let result = sock_merchant(&socks);
    println!("{}", result);
}

    fn read_line_as_vec_i32() -> Vec<i32> {
        let stdin = io::stdin();
        
        let numbers: Vec<i32> = stdin.lock()
          .lines().next().unwrap().unwrap()
          .trim().split(' ')
          .map(|s| s.parse().unwrap())
          .collect();

        return numbers;
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
