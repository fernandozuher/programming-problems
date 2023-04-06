// Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

fn main() {
    let initial_string: String = read!();
    let final_string: String = read!();
    let number_of_operations: usize = read!();

    let response: bool = append_and_delete(initial_string, final_string, number_of_operations);
    print_output(response);
}

fn append_and_delete(
    initial_string: String,
    final_string: String,
    number_of_operations: usize,
) -> bool {
    let common_prefix_size_between_strings: usize =
        find_common_prefix_size_between_strings(initial_string.clone(), final_string.clone());

    let size_of_different_characters_from_initial_string: usize =
        initial_string.len() - common_prefix_size_between_strings;

    let size_of_different_characters_from_final_string: usize =
        final_string.len() - common_prefix_size_between_strings;

    let minimal_quantity_of_operations_to_replace_string: usize =
        size_of_different_characters_from_initial_string
            + size_of_different_characters_from_final_string;

    let remaining_operations: i32 =
        number_of_operations as i32 - minimal_quantity_of_operations_to_replace_string as i32;

    return are_operations_suitable_to_replace_string(
        remaining_operations,
        common_prefix_size_between_strings,
    );
}

fn find_common_prefix_size_between_strings(initial_string: String, final_string: String) -> usize {
    let mut size: usize = 0;
    while size != initial_string.len()
        && size != final_string.len()
        && initial_string.chars().nth(size).unwrap() == final_string.chars().nth(size).unwrap()
    {
        size += 1;
    }
    return size;
}

fn are_operations_suitable_to_replace_string(
    number_of_operations: i32,
    common_prefix_size_between_strings: usize,
) -> bool {
    if number_of_operations < 0
        || (are_operations_bigger_than_zero_and_odd(number_of_operations)
            && are_not_operations_enough_to_remove_and_replace_common_prefix(
                number_of_operations,
                common_prefix_size_between_strings,
            ))
    {
        return false;
    }
    return true;
}

fn are_operations_bigger_than_zero_and_odd(number_of_operations: i32) -> bool {
    return number_of_operations > 0 && number_of_operations % 2 == 1;
}

fn are_not_operations_enough_to_remove_and_replace_common_prefix(
    number_of_operations: i32,
    common_prefix_size_between_strings: usize,
) -> bool {
    return number_of_operations < (common_prefix_size_between_strings * 2) as i32;
}

fn print_output(response: bool) {
    if response {
        println!("Yes");
    } else {
        println!("No");
    }
}
