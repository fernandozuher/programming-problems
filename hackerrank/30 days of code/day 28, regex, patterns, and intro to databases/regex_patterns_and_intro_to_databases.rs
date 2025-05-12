// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

use text_io::{read, scan};

fn main() {
    let n: usize = read!();
    let mut names: Vec<String> = collect_gmail_users(n);
    names.sort();
    for x in names {
        println!("{}", x);
    }
}

fn collect_gmail_users(n: usize) -> Vec<String> {
    let mut names: Vec<String> = Vec::new();

    for _ in 0..n {
        let (name, email): (String, String);
        scan!("{} {}", name, email);
        if email.ends_with("@gmail.com") {
            names.push(name);
        }
    }

    names
}
