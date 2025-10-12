// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

use text_io::read;

fn main() {
    let lower: usize = read!();
    let upper: usize = read!();
    let mut valid_range: bool = false;

    (lower..=upper).for_each(|x| {
        if is_number_kaprekar(x) {
            print!("{} ", x);
            valid_range = true;
        }
    });

    if !valid_range {
        println!("INVALID RANGE");
    }
}

fn is_number_kaprekar(number: usize) -> bool {
    let square_number: usize = number.pow(2);
    let divisor: usize = 10_usize.pow(number_digits(number));
    let (left_number, right_number) = (square_number / divisor, square_number % divisor);
    number == left_number + right_number
}

fn number_digits(n: usize) -> u32 {
    n.to_string().len() as u32
}
