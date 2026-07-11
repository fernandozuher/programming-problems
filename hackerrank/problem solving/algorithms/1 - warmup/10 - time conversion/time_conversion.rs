// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

use text_io::read;

fn main() {
    let time: String = read!();
    print!("{}", to_24_hour_time(&time));
}

// T: O(1)
// S: O(1) extra space
fn to_24_hour_time(hour_12: &String) -> String {
    let mut hour_24: String = hour_12[0..8].to_string();
    let hour = &hour_12[0..2];
    let day_period = &hour_12[8..9];

    if (hour == "12" && day_period == "A") || (hour != "12" && day_period == "P") {
        let new_hour: String = gen_new_hour(day_period, hour);
        hour_24 = hour_24.replace(hour, &new_hour);
    }

    hour_24
}

fn gen_new_hour(day_period: &str, hour: &str) -> String {
    if day_period == "A" {
        return "00".to_string();
    }
    let mut new_hour: i32 = hour.parse().unwrap();
    new_hour += 12;
    new_hour.to_string()
}
