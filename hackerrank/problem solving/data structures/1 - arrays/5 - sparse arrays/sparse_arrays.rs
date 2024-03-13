// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

use std::collections::HashMap;
use text_io::read;

fn main() {
    let mut n: usize = read!();
    let mut input_strings: HashMap<String, i32> = read_input(n);

    n = read!();
    let result: Vec<i32> = read_queries_and_count_matches(&mut input_strings, n);
    result.iter().for_each(|x| println!("{}", x))
}

fn read_input(n: usize) -> HashMap<String, i32> {
    let mut input = HashMap::new();
    for _i in 0..n {
        let line: String = read!();
        *input.entry(line.to_owned()).or_default() += 1;
    }
    return input;
}

fn read_queries_and_count_matches(input: &mut HashMap<String, i32>, n: usize) -> Vec<i32> {
    let mut result: Vec<i32> = Vec::new();
    for _i in 0..n {
        let query: String = read!();
        let count: i32 = *input.entry(query.to_owned()).or_default();
        result.push(count);
    }
    return result;
}
