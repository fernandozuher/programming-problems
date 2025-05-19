// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

use text_io::read;

const TRIPLET_SIZE: usize = 3;

fn main() {
    let triplet_a: [i32; TRIPLET_SIZE] = read_input();
    let triplet_b: [i32; TRIPLET_SIZE] = read_input();
    let (score_a, score_b) = compare_triplets(triplet_a, triplet_b);
    println!("{} {}", score_a, score_b);
}

fn read_input() -> [i32; TRIPLET_SIZE] {
    let mut array: [i32; TRIPLET_SIZE] = [0; TRIPLET_SIZE];
    array.iter_mut().for_each(|x| *x = read!());
    array
}

fn compare_triplets(triplet_a: [i32; TRIPLET_SIZE], triplet_b: [i32; TRIPLET_SIZE]) -> (i32, i32) {
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
