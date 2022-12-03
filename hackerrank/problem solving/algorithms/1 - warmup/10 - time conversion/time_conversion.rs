use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write};

/*
 * Complete the 'time_conversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

fn time_conversion(time: &str) -> String {
    let mut converted_time: String = time[0..8].to_string();
    let hour_string = &time[0..2];
    let period_of_day = &time[8..9];

    if hour_string == "12" {
        if period_of_day == "A" {
            converted_time = converted_time.replace(hour_string, "00");
        }
    }
    else if period_of_day == "P" {
        let mut hour: i32 = hour_string.parse().unwrap();
        hour += 12;
        converted_time = converted_time.replace(hour_string, &hour.to_string());
    }
    return converted_time;
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();

    let s = stdin_iterator.next().unwrap().unwrap();

    let result = time_conversion(&s);

    writeln!(&mut fptr, "{}", result).ok();
}
