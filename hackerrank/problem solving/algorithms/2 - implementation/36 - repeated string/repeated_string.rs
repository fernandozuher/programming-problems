// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

use num::integer::div_rem;
use text_io::read;

fn main() {
    let string: String = read!();
    let n_characters: i64 = read!();
    const letter: char = 'a';
    println!(
        "{}",
        count_in_repeated_string(string.as_str(), letter, n_characters)
    );
}

fn count_in_repeated_string(string: &str, letter: char, n_characters: i64) -> i64 {
    let (repeated_entire_string, n_substring): (usize, usize) =
        div_rem(n_characters as usize, string.len());
    let substring = &string[..n_substring];

    let mut quantity: i64 = count(string, letter);
    quantity *= repeated_entire_string as i64;
    quantity += count(substring, letter);

    return quantity;
}

fn count(string: &str, letter: char) -> i64 {
    return string.matches(letter).count() as i64;
}
