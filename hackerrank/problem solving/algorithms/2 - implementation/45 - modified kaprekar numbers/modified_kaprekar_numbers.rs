// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

use text_io::read;

fn main() {
    let lower: usize = read!();
    let upper: usize = read!();
    let mut valid_range: bool = false;

    for num in lower..=upper {
        if is_number_kaprekar(num) {
            print!("{} ", num);
            valid_range = true;
        }
    }

    if !valid_range {
        println!("INVALID RANGE");
    }
}

// log n: for calculating number of digits
// T: O(log n)
// S: O(1) extra space
fn is_number_kaprekar(n: usize) -> bool {
    let square_number: usize = n.pow(2);
    let divisor: usize = 10_usize.pow(number_digits(n));
    let (left_number, right_number) = (square_number / divisor, square_number % divisor);
    n == left_number + right_number
}

fn number_digits(n: usize) -> u32 {
    (n as f64).log10() as u32 + 1
}
