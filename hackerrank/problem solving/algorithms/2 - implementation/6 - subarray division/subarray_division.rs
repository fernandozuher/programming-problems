// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let chocolate_squares = read_int_array(n);

    const n_day_month: usize = 2;
    let day_month = read_int_array(n_day_month);

    println!("{}", birthday(&chocolate_squares, &day_month));
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn birthday(chocolate_squares: &Vec<i32>, day_month: &Vec<i32>) -> i32 {
    let mut ways_bar_can_be_divided = 0;
    let day = day_month[0];
    let month = day_month[1] as usize;

    for i in 0..(chocolate_squares.len() - month + 1) {
        let mut sum = 0;

        for j in i..(i + month) {
            sum += chocolate_squares[j];
        }

        if sum == day {
            ways_bar_can_be_divided += 1;
        }
    }

    return ways_bar_can_be_divided;
}
