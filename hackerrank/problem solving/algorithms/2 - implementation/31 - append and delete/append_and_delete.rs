// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

use std::cmp::min;
use text_io::read;

fn main() {
    let initial_string: String = read!();
    let final_string: String = read!();
    let operations: i32 = read!();

    if append_and_delete(&initial_string, &final_string, operations) {
        println!("Yes");
    } else {
        println!("No");
    }
}

fn append_and_delete(initial_string: &String, final_string: &String, operations: i32) -> bool {
    let common_prefix_size_between_strings: usize =
        find_common_prefix_size_between_strings(initial_string, final_string);

    let size_of_different_characters_from_initial_string: usize =
        initial_string.len() - common_prefix_size_between_strings;

    let size_of_different_characters_from_final_string: usize =
        final_string.len() - common_prefix_size_between_strings;

    let minimal_quantity_of_operations_to_replace_string: usize =
        size_of_different_characters_from_initial_string
            + size_of_different_characters_from_final_string;

    let remaining_operations: i32 =
        operations - minimal_quantity_of_operations_to_replace_string as i32;

    return are_operations_suitable_to_replace_string(
        remaining_operations,
        common_prefix_size_between_strings,
    );
}

fn find_common_prefix_size_between_strings(
    initial_string: &String,
    final_string: &String,
) -> usize {
    let mut size: usize = 0;
    let mut n: i32 = min(initial_string.len(), final_string.len()) as i32;

    while n > 0
        && initial_string.chars().nth(size).unwrap() == final_string.chars().nth(size).unwrap()
    {
        size += 1;
        n -= 1;
    }
    return size;
}

fn are_operations_suitable_to_replace_string(
    operations: i32,
    common_prefix_size_between_strings: usize,
) -> bool {
    if operations < 0
        || (are_operations_bigger_than_zero_and_odd(operations)
            && are_not_operations_enough_to_remove_and_replace_common_prefix(
                operations,
                common_prefix_size_between_strings,
            ))
    {
        return false;
    }
    return true;
}

fn are_operations_bigger_than_zero_and_odd(operations: i32) -> bool {
    return operations > 0 && operations & 1 == 1;
}

fn are_not_operations_enough_to_remove_and_replace_common_prefix(
    operations: i32,
    common_prefix_size_between_strings: usize,
) -> bool {
    return (operations as usize) < common_prefix_size_between_strings * 2;
}
