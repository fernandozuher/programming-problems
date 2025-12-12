// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

use combinations::Combinations;
use text_io::read;

fn main() {
    let attendees: usize = read!();
    let _: usize = read!();
    let binaries: Vec<String> = read_binaries(attendees);
    for x in acm_team(binaries) {
        println!("{}", x);
    }
}

fn read_binaries(n: usize) -> Vec<String> {
    (0..n).map(|_| read!()).collect()
}

fn acm_team(binaries: Vec<String>) -> [usize; 2] {
    let mut max_subjects: usize = 0;
    let mut teams_with_max: usize = 0;

    for c in Combinations::new(binaries, 2).collect::<Vec<_>>() {
        let known_subjects: usize = count_subjects_known_by_2_teams(&c[0], &c[1]);

        if known_subjects > max_subjects {
            max_subjects = known_subjects;
            teams_with_max = 1;
        } else if known_subjects == max_subjects {
            teams_with_max += 1;
        }
    }

    [max_subjects, teams_with_max]
}

fn count_subjects_known_by_2_teams(a: &str, b: &str) -> usize {
    a.chars()
        .zip(b.chars())
        .filter(|(ac, bc)| *ac == '1' || *bc == '1')
        .count()
}
