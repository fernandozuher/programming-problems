// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

fn main() {
    let attendees: u32 = read!();
    let _topics: u32 = read!();
    let binary_strings: Vec<String> = read_binary_strings(attendees);

    let output: Vec<u32> = acm_team(binary_strings);
    print_array(output);
}

fn read_binary_strings(n_strings: u32) -> Vec<String> {
    let mut binary_strings: Vec<String> = Vec::new();
    binary_strings.resize_with(n_strings as usize, || read!());
    return binary_strings;
}

fn acm_team(binary_strings: Vec<String>) -> Vec<u32> {
    let mut teams_that_know_maximum_subjects: u32 = 0;
    let mut maximum_subjects_known_by_teams: u32 = 0;

    for i in 0..(binary_strings.len() - 1) {
        for j in (i + 1)..binary_strings.len() {
            let temporary_maximum_subjects_known_by_teams: u32 =
                calculate_maximum_subjects_known_by_team(
                    binary_strings[i].clone(),
                    binary_strings[j].clone(),
                );

            if temporary_maximum_subjects_known_by_teams > maximum_subjects_known_by_teams {
                maximum_subjects_known_by_teams = temporary_maximum_subjects_known_by_teams;
                teams_that_know_maximum_subjects = 1;
            } else if temporary_maximum_subjects_known_by_teams == maximum_subjects_known_by_teams {
                teams_that_know_maximum_subjects += 1;
            }
        }
    }

    let output: Vec<u32> = vec![
        maximum_subjects_known_by_teams,
        teams_that_know_maximum_subjects,
    ];
    return output;
}

fn calculate_maximum_subjects_known_by_team(
    binary_string_1: String,
    binary_string_2: String,
) -> u32 {
    let mut temporary_maximum_subjects_known_by_teams: u32 = 0;

    for it in binary_string_1.chars().zip(binary_string_2.chars()) {
        let (character_string_1, character_string_2) = it;

        if character_string_1 == '1' || character_string_2 == '1' {
            temporary_maximum_subjects_known_by_teams += 1;
        }
    }

    return temporary_maximum_subjects_known_by_teams;
}

fn print_array(array: Vec<u32>) {
    for element in array {
        println!("{}", element);
    }
}
