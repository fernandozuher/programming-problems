// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    (0..n)
        .map(|_| {
            let n_students_arrival_time: usize = read!();
            let cancellation_threshold: i32 = read!();
            let students_arrival_times: Vec<i32> = read_numbers(n_students_arrival_time);
            angry_professor(&students_arrival_times, cancellation_threshold)
        })
        .for_each(|x| println!("{}", x));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn angry_professor(arrival_times: &[i32], cancellation_threshold: i32) -> String {
    let on_time: i32 = arrival_times.iter().filter(|&&t| t <= 0).count() as i32;
    if on_time < cancellation_threshold {
        String::from("YES")
    } else {
        String::from("NO")
    }
}
