// Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

use substring::Substring;
use text_io::read;

fn main() {
    let input_string: String = read!();
    let n_characters: usize = read!();

    let quantity_of_a: usize = find_quantity_of_a_in_repeated_string(input_string, n_characters);
    println!("{}", quantity_of_a);
}

fn find_quantity_of_a_in_repeated_string(input_string: String, n_characters: usize) -> usize {
    let mut quantity_of_a: usize = find_quantity_of_a_in_string(input_string.clone());
    quantity_of_a *= find_quantity_of_repeated_entire_string(n_characters, input_string.len());
    quantity_of_a += find_quantity_of_remaining_a(n_characters, input_string.clone());

    return quantity_of_a;
}

fn find_quantity_of_a_in_string(input_string: String) -> usize {
    let mut quantity_of_a: usize = 0;

    for character in input_string.chars() {
        if character == 'a' {
            quantity_of_a += 1;
        }
    }

    return quantity_of_a;
}

fn find_quantity_of_repeated_entire_string(n_characters: usize, size_string: usize) -> usize {
    let n_strings: usize = n_characters / size_string;
    return n_strings;
}

fn find_quantity_of_remaining_a(n_characters: usize, input_string: String) -> usize {
    let n_remaining_characters_of_string: usize = n_characters % input_string.len();

    if n_remaining_characters_of_string == 0 {
        return 0;
    }

    let sub_string: String =
        (*input_string.substring(0, n_remaining_characters_of_string)).to_string();
    return find_quantity_of_a_in_string(sub_string);
}
