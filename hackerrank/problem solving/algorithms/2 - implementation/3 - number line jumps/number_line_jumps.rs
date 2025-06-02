// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

use text_io::read;

fn main() {
    const N: usize = 4;
    let positions_and_velocities: Vec<i32> = read_numbers(N);
    if kangaroo(&positions_and_velocities) {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn kangaroo(positions_and_velocities: &[i32]) -> bool {
    let x1: i32 = positions_and_velocities[0];
    let v1: i32 = positions_and_velocities[1];
    let x2: i32 = positions_and_velocities[2];
    let v2: i32 = positions_and_velocities[3];

    if v1 == v2 {
        return x1 == x2;
    }

    let distance_diff = x2 - x1;
    let velocity_diff = v1 - v2;
    distance_diff * velocity_diff >= 0 && distance_diff % velocity_diff == 0
}
