// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut cancelled_classes = vec![false; n];

    for cancelled in cancelled_classes.iter_mut() {
        let n_students_arrival_time: usize = read!();
        let cancellation_threshold: i32 = read!();
        let students_arrival_time: Vec<i32> = read_int_array(n_students_arrival_time);
        *cancelled = angry_professor(&students_arrival_time, cancellation_threshold)
    }

    for cancelled in cancelled_classes {
        println!("{}", if cancelled { "YES" } else { "NO" });
    }
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn angry_professor(students_arrival_time: &Vec<i32>, cancellation_threshold: i32) -> bool {
    let cancelled_class: bool =
        count_early_arrival_time(students_arrival_time) < cancellation_threshold;
    return cancelled_class;
}

fn count_early_arrival_time(students_arrival_time: &Vec<i32>) -> i32 {
    let mut early_arrival_time_count: i32 = 0;

    for arrival_time in students_arrival_time.iter() {
        if *arrival_time <= 0 {
            early_arrival_time_count += 1;
        }
    }

    return early_arrival_time_count;
}
