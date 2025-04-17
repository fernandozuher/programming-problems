// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n_tests: usize = read!();
    process_prime_tests(n_tests);
}

fn process_prime_tests(n_tests: usize) {
    for _ in 0..n_tests {
        let n: usize = read!();
        if is_prime(n) {
            println!("Prime");
        } else {
            println!("Not prime");
        }
    }
}

fn is_prime(n: usize) -> bool {
    if n <= 1 {
        return false;
    }
    if n == 2 {
        return true;
    }
    if n % 2 == 0 {
        return false;
    }

    let limit: usize = (n as f64).sqrt() as usize;
    for divisor in (3..=limit).step_by(2) {
        if n % divisor == 0 {
            return false;
        }
    }
    true
}
