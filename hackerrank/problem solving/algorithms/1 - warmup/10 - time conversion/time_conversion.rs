// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

use text_io::read;

fn main() {
    let time: String = read!();
    println!("{}", time_conversion(&time));
}

fn time_conversion(time: &String) -> String {
    let mut converted_time: String = time[0..8].to_string();
    let hour = &time[0..2];
    let period_of_day = &time[8..9];

    if hour == "12" {
        if period_of_day == "A" {
            let midnight: &str = "00";
            converted_time = converted_time.replace(hour, midnight);
        }
    } else if period_of_day == "P" {
        let mut new_hour: i32 = hour.parse().unwrap();
        new_hour += 12;
        converted_time = converted_time.replace(hour, &new_hour.to_string());
    }

    return converted_time;
}
