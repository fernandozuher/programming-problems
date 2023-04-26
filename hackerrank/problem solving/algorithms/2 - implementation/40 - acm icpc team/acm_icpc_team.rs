// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

fn main() {
    let attendees: u32 = read!();
    let _topics: u32 = read!();
    let binary_strings: Vec<String> = read_binary_strings(attendees);

    let output: Vec<u32> = find_maximum_subjects_and_teams_that_know_them(binary_strings);
    print_array(output);
}

fn read_binary_strings(n_strings: u32) -> Vec<String> {
    let mut binary_strings: Vec<String> = Vec::new();
    binary_strings.resize_with(n_strings as usize, || read!());
    return binary_strings;
}

fn find_maximum_subjects_and_teams_that_know_them(binary_strings: Vec<String>) -> Vec<u32> {
    let mut maximum_subjects_known_by_teams: u32 = 0;
    let mut teams_that_know_maximum_subjects: u32 = 0;

    for i in 0..(binary_strings.len() - 1) {
        for j in (i + 1)..binary_strings.len() {
            let subjects_known_by_2_teams: u32 = count_subjects_known_by_2_teams(
                binary_strings[i].clone(),
                binary_strings[j].clone(),
            );
            update_maximum_subjects_and_teams_that_know_them(
                subjects_known_by_2_teams,
                &mut maximum_subjects_known_by_teams,
                &mut teams_that_know_maximum_subjects,
            );
        }
    }

    let output: Vec<u32> = vec![
        maximum_subjects_known_by_teams,
        teams_that_know_maximum_subjects,
    ];
    return output;
}

fn count_subjects_known_by_2_teams(binary_string_1: String, binary_string_2: String) -> u32 {
    let mut subjects_known_by_2_teams: u32 = 0;

    for it in binary_string_1.chars().zip(binary_string_2.chars()) {
        let (character_string_1, character_string_2) = it;

        if character_string_1 == '1' || character_string_2 == '1' {
            subjects_known_by_2_teams += 1;
        }
    }

    return subjects_known_by_2_teams;
}

fn update_maximum_subjects_and_teams_that_know_them(
    subjects_known_by_2_teams: u32,
    maximum_subjects_known_by_teams: &mut u32,
    teams_that_know_maximum_subjects: &mut u32,
) {
    if subjects_known_by_2_teams > *maximum_subjects_known_by_teams {
        *maximum_subjects_known_by_teams = subjects_known_by_2_teams;
        *teams_that_know_maximum_subjects = 1;
    } else if subjects_known_by_2_teams == *maximum_subjects_known_by_teams {
        *teams_that_know_maximum_subjects += 1;
    }
}

fn print_array(array: Vec<u32>) {
    for element in array {
        println!("{}", element);
    }
}
