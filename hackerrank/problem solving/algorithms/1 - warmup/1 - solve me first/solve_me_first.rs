use std::io;

fn solve_me_first(num1: i32, num2: i32) -> i32 {
    return num1 + num2;
}

fn main() {
    let mut _num_str_1 = String::new();
    let mut _num_str_2 = String::new();

    io::stdin().read_line(&mut _num_str_1).ok().expect("read error");
    io::stdin().read_line(&mut _num_str_2).ok().expect("read error");

    let mut _num_1 : i32 = _num_str_1.trim().parse().ok().expect("parse error");
    let mut _num_2 : i32 = _num_str_2.trim().parse().ok().expect("parse error");

    let sum = solve_me_first(_num_1, _num_2);
    println!("{}", sum);
}
