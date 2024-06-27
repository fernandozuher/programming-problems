// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let chocolate_squares = read_int_array(n);
    const N_DAY_MONTH: usize = 2;
    let day_month = read_int_array(N_DAY_MONTH);
    println!("{}", birthday(&chocolate_squares, &day_month));
}

    fn read_int_array(n: usize) -> Vec<i32> {
        return (0..n).map(|_| read!()).collect();
    }

    fn birthday(chocolate_squares: &[i32], day_month: &[i32]) -> i32 {
        let mut ways_bar_can_be_divided = 0;
        let day = day_month[0];
        let month = day_month[1] as usize;

        for i in 0..(chocolate_squares.len() - month + 1) {
            let sum: i32 = (&chocolate_squares[i..i + month]).iter().sum();
            if sum == day {
                ways_bar_can_be_divided += 1;
            }
        }

        return ways_bar_can_be_divided;
    }
