// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let array = read_int_array(n);

    let records = breaking_records(&array);
    println!("{} {}", records[0], records[1]);
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn breaking_records(scores: &Vec<i32>) -> Vec<i32> {
    let (mut most_points, mut breaking_most_points_records) = (scores[0], 0);
    let (mut least_points, mut breaking_least_points_records) = (scores[0], 0);

    for score in scores {
        if *score > most_points {
            most_points = *score;
            breaking_most_points_records += 1;
        } else if *score < least_points {
            least_points = *score;
            breaking_least_points_records += 1;
        }
    }

    return vec![breaking_most_points_records, breaking_least_points_records];
}
