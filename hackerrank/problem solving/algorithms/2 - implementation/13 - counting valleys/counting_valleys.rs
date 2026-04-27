// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

use text_io::read;

fn main() {
    let _: usize = read!();
    let steps: String = read!();
    println!("{}", counting_valleys(&steps));
}

// n: length of steps
// T: O(n)
// S: O(1) extra space
fn counting_valleys(steps: &str) -> i32 {
    let mut valleys: i32 = 0;
    let mut current_altitude: i32 = 0;

    for step in steps.chars() {
        let was_below_sea_level: bool = current_altitude < 0;
        current_altitude += if step == 'D' { -1 } else { 1 };
        let is_in_sea_level_from_valley = was_below_sea_level && current_altitude == 0;
        if is_in_sea_level_from_valley {
            valleys += 1;
        }
    }

    valleys
}
