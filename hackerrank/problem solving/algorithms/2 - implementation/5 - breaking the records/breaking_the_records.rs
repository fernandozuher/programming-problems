// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let array: Vec<i32> = read_int_array(n);
    let (breaking_most_points_records, breaking_least_points_records) = breaking_records(&array);
    println!("{} {}", breaking_most_points_records, breaking_least_points_records);
}
    fn read_int_array(n: usize) -> Vec<i32> {
        return (0..n).map(|_| read!()).collect();
    }
    
    fn breaking_records(scores: &[i32]) -> (i32, i32) {
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
    
        return (breaking_most_points_records, breaking_least_points_records);
    }
