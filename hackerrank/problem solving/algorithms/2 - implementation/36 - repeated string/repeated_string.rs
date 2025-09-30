// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

use num::integer::div_rem;
use text_io::read;

fn main() {
    let string: String = read!();
    let n_characters: usize = read!();
    const LETTER: char = 'a';
    println!(
        "{}",
        count_in_repeated_string(string.as_str(), LETTER, n_characters)
    );
}

fn count_in_repeated_string(string: &str, letter: char, n_characters: usize) -> usize {
    let (full_repeats, n_substring): (usize, usize) = div_rem(n_characters, string.len());
    let substring = &string[..n_substring];

    let mut quantity: usize = count(string, letter);
    quantity *= full_repeats;
    quantity + count(substring, letter)
}

fn count(string: &str, letter: char) -> usize {
    string.chars().filter(|&c| c == letter).count()
}
