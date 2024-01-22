// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: i32 = read!();
    let array: String = read!();
    println!("{}", counting_valleys(&array));
}

fn counting_valleys(steps: &String) -> i32 {
    let mut current_altitude: i32 = 0;
    let mut traversed_valleys: i32 = 0;

    for step in steps.chars() {
        let mut was_travessing_a_valley: bool = current_altitude < 0;
        current_altitude += if step == 'D' { -1 } else { 1 };

        if is_in_sea_level_from_valley(was_travessing_a_valley, current_altitude) {
            traversed_valleys += 1;
        }
    }

    return traversed_valleys;
}

fn is_in_sea_level_from_valley(was_travessing_a_valley: bool, current_altitude: i32) -> bool {
    return was_travessing_a_valley && current_altitude == 0;
}
