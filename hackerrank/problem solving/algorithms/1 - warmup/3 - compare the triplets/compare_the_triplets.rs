// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

use text_io::read;

fn main() {
    const N: usize = 3;
    let array1: Vec<i32> = read_int_array(N);
    let array2: Vec<i32> = read_int_array(N);
    let (player1, player2) = compare_triplets(&array1, &array2);
    print!("{} {}", player1, player2);
}

fn read_int_array(n: usize) -> Vec<i32> {
    return (0..n).map(|_| read!()).collect();
}

fn compare_triplets(array1: &[i32], array2: &[i32]) -> (i32, i32) {
    let (mut player1, mut player2) = (0, 0);

    for (p1, p2) in array1.iter().zip(array2.iter()) {
        if p1 > p2 {
            player1 += 1;
        } else if p2 > p1 {
            player2 += 1;
        }
    }

    return (player1, player2);
}
