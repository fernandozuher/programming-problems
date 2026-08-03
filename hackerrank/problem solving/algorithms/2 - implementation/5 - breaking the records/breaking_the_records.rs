// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

fn main() {
    let n: usize = text_io::read!();
    let (most_record_breaks, least_record_breaks) = breaking_records(&read_nums(n));
    println!("{} {}", most_record_breaks, least_record_breaks);
}

fn read_nums(n: usize) -> Vec<i32> {
    (0..n).map(|_| text_io::read!()).collect()
}

// n: length of scores
// T: O(n)
// S: O(1) extra space
fn breaking_records(scores: &[i32]) -> (i32, i32) {
    let (mut most_points, mut least_points) = (scores[0], scores[0]);
    let (mut most_record_breaks, mut least_record_breaks) = (0, 0);

    for &score in scores {
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
