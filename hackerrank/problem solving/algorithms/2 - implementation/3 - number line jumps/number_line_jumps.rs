// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

use text_io::read;

fn main() {
    let initial_state: (i32, i32, i32, i32) = read_input();
    if kangaroo(&initial_state) {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn read_input() -> (i32, i32, i32, i32) {
    (read!(), read!(), read!(), read!())
}

// T: O(1)
// S: O(1) extra space
fn kangaroo(initialState: &(i32, i32, i32, i32)) -> bool {
    let (x1, v1, x2, v2) = initialState;

    if v1 == v2 {
        return x1 == x2;
    }

    let distance_diff = x2 - x1;
    let velocity_diff = v1 - v2;
    distance_diff * velocity_diff >= 0 && distance_diff % velocity_diff == 0
}
