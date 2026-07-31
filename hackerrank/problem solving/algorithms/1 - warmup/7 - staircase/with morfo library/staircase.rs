// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

fn main() {
    let n: usize = morfo::read();
    staircase(n);
}

// T: O(n^2)
// S: O(n) extra space
fn staircase(n: usize) {
    for i in 1..=n {
        let spaces = " ".repeat(n - i);
        let hashes = "#".repeat(i);
        println!("{}{}", spaces, hashes);
    }
}
