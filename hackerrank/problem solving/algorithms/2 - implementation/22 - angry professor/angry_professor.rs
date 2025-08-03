// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();

    (0..n)
        .map(|_| {
            let n: usize = read!();
            let threshold: i32 = read!();
            let students_arrival_times: Vec<i32> = read_numbers(n);
            angry_professor(&students_arrival_times, threshold)
        })
        .for_each(|cancelled| {
            if cancelled {
                println!("YES")
            } else {
                println!("NO")
            }
        })
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn angry_professor(arrival_times: &[i32], threshold: i32) -> bool {
    let on_time: i32 = arrival_times.iter().filter(|&&t| t <= 0).count() as i32;
    on_time < threshold
}
