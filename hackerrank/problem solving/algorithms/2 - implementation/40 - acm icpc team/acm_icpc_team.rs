// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

use text_io::read;

fn main() {
    let attendees: usize = read!();
    let _topics: usize = read!();
    let binary_strings: Vec<String> = read_binaries(attendees);
    print_array(find_maximum_subjects_and_teams_that_know_them(
        binary_strings,
    ));
}

fn read_binaries(n: usize) -> Vec<String> {
    let mut binaries: Vec<String> = Vec::new();
    binaries.resize_with(n, || read!());
    return binaries;
}

fn find_maximum_subjects_and_teams_that_know_them(binary_strings: Vec<String>) -> [i32; 2] {
    let mut maximum_subjects_known_by_teams: i32 = 0;
    let mut teams_that_know_maximum_subjects: i32 = 0;

    for (i, previous) in binary_strings[..binary_strings.len() - 1]
        .iter()
        .enumerate()
    {
        for current in &binary_strings[i + 1..] {
            let subjects_known_by_2_teams: i32 = count_subjects_known_by_2_teams(previous, current);

            update_maximum_subjects_and_teams_that_know_them(
                subjects_known_by_2_teams,
                &mut maximum_subjects_known_by_teams,
                &mut teams_that_know_maximum_subjects,
            );
        }
    }

    return [
        maximum_subjects_known_by_teams,
        teams_that_know_maximum_subjects,
    ];
}

fn count_subjects_known_by_2_teams(binary_string_1: &String, binary_string_2: &String) -> i32 {
    let mut subjects_known_by_2_teams: i32 = 0;
    for (ch1, ch2) in binary_string_1.chars().zip(binary_string_2.chars()) {
        if ch1 == '1' || ch2 == '1' {
            subjects_known_by_2_teams += 1;
        }
    }
    return subjects_known_by_2_teams;
}

fn update_maximum_subjects_and_teams_that_know_them(
    subjects_known_by_2_teams: i32,
    maximum_subjects_known_by_teams: &mut i32,
    teams_that_know_maximum_subjects: &mut i32,
) {
    if subjects_known_by_2_teams > *maximum_subjects_known_by_teams {
        *maximum_subjects_known_by_teams = subjects_known_by_2_teams;
        *teams_that_know_maximum_subjects = 1;
    } else if subjects_known_by_2_teams == *maximum_subjects_known_by_teams {
        *teams_that_know_maximum_subjects += 1;
    }
}

fn print_array(array: [i32; 2]) {
    for x in array {
        println!("{}", x);
    }
}
