// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    println!("{}", minimum_number_of_jumps(&read_numbers(n)));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn minimum_number_of_jumps(clouds: &[i32]) -> i32 {
    let mut i: usize = 0;
    let n: usize = clouds.len() - 1;
    let mut jumps: i32 = 0;

    while i < n {
        i += next_jump(i, clouds);
        jumps += 1;
    }
    jumps
}

fn next_jump(index: usize, clouds: &[i32]) -> usize {
    let mut is_next_second_cloud_cumulus = false;
    if index + 2 < clouds.len() {
        is_next_second_cloud_cumulus = clouds[index + 2] == 0;
    }

    if is_next_second_cloud_cumulus {
        2
    } else {
        1
    }
}
