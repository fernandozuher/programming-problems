// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: i32 = read!();

    for _ in 0..n {
        let number: i32 = read!();

        if number == 1 {
            println!("Not prime");
            continue;
        }

        let mut i: i32 = 2;
        let limit: i32 = (number as f64).sqrt() as i32;
        while i <= limit {
            if number % i == 0 {
                println!("Not prime");
                break;
            }
            i += 1;
        }

        if i > limit {
            println!("Prime");
        }
    }
}
