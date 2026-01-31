// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    println!("{}", min_jumps(&read_numbers(n)));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

// n: length of array clouds
// T: O(n)
// S: O(1) extra space
fn min_jumps(clouds: &[i32]) -> i32 {
    let mut i: usize = 0;
    let n: usize = clouds.len() - 1;
    let mut jumps: i32 = 0;

    while i < n {
        i += skip(i, clouds);
        jumps += 1;
    }
    jumps
}

fn skip(idx: usize, clouds: &[i32]) -> usize {
    if is_next_second_cloud_cumulus(idx, clouds) { 2 } else { 1 }
}

fn is_next_second_cloud_cumulus(idx: usize, clouds: &[i32]) -> bool {
    idx + 2 < clouds.len() && clouds[idx + 2] == 0
}
