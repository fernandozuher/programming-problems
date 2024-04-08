// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut clouds: Vec<i32> = vec![0; n];
    clouds.fill_with(|| read!());
    println!("{}", minimum_number_of_jumps(&clouds));
}

fn minimum_number_of_jumps(clouds: &Vec<i32>) -> i32 {
    let mut i: usize = 0;
    let n: usize = clouds.len() - 1;
    let mut jumps: i32 = 0;

    while i < n {
        i += next_jump(i, clouds);
        jumps += 1;
    }
    return jumps;
}

fn next_jump(index: usize, clouds: &Vec<i32>) -> usize {
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
