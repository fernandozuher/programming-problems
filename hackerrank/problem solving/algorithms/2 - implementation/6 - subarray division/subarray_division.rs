// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let chocolate_squares = read_numbers(n);
    const N_DAY_MONTH: usize = 2;
    let day_month = read_numbers(N_DAY_MONTH);
    println!("{}", birthday(&chocolate_squares, &day_month));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn birthday(chocolate_squares: &[i32], day_month: &[i32]) -> i32 {
    let day = day_month[0];
    let month = day_month[1] as usize;

    if month > chocolate_squares.len() {
        return 0;
    }

    let mut sum: i32 = chocolate_squares[..month].iter().sum();
    let mut ways_bar_can_be_divided: i32 = if sum == day { 1 } else { 0 };

    (month..chocolate_squares.len()).for_each(|i| {
        sum += chocolate_squares[i] - chocolate_squares[i - month];
        if sum == day {
            ways_bar_can_be_divided += 1;
        }
    });

    ways_bar_can_be_divided
}
