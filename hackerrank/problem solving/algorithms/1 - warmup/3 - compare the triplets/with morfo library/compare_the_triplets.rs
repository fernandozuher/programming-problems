// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

use morfo::read_n;

fn main() {
    const N: usize = 3;
    let triplet_a: Vec<i32> = morfo::read_n(N);
    let triplet_b: Vec<i32> = morfo::read_n(N);
    let (score_a, score_b) = compute_triplet_scores(triplet_a, triplet_b);
    println!("{} {}", score_a, score_b);
}

// n: length of a and b = 3
// T: O(3) => O(1)
// S: O(1) extra space
fn compute_triplet_scores(triplet_a: Vec<i32>, triplet_b: Vec<i32>) -> (i32, i32) {
    let (mut score_a, mut score_b) = (0, 0);

    for (ta, tb) in triplet_a.iter().zip(triplet_b.iter()) {
        if ta > tb {
            score_a += 1;
        } else if tb > ta {
            score_b += 1;
        }
    }

    (score_a, score_b)
}
