// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let scores: Vec<i32> = read_numbers(n);
    let (most_record_breaks, least_record_breaks) = breaking_records(&scores);
    println!("{} {}", most_record_breaks, least_record_breaks);
}
fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn breaking_records(scores: &[i32]) -> (i32, i32) {
    let (mut most_points, mut least_points) = (scores[0], scores[0]);
    let (mut most_record_breaks, mut least_record_breaks) = (0, 0);

    for &score in &scores[1..] {
        if score > most_points {
            most_points = score;
            most_record_breaks += 1;
        } else if score < least_points {
            least_points = score;
            least_record_breaks += 1;
        }
    }

    (most_record_breaks, least_record_breaks)
}
