use std::io::{self, BufRead};

/*
 * Complete the 'mini_max_sum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

fn mini_max_sum(arr: &[i32]) {
    let arr2: &mut[i32] = &mut arr.to_owned();
    arr2.sort();

    let mut total_sum: i64 = 0;
    for number in arr2.iter() {
        total_sum += *number as i64;
    }

    let min_sum: i64 = total_sum - arr2[arr2.len() - 1] as i64;
    let max_sum: i64 = total_sum - arr2[0] as i64;
    println!("{} {}", min_sum, max_sum);
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let arr: Vec<i32> = stdin_iterator.next().unwrap().unwrap()
        .trim_end()
        .split(' ')
        .map(|s| s.to_string().parse::<i32>().unwrap())
        .collect();

    mini_max_sum(&arr);
}
