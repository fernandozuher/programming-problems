// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

use text_io::read;

fn main() {
    let attendees: usize = read!();
    let _: usize = read!();
    let binaries: Vec<String> = read_binaries(attendees);
    acm_team(&binaries).iter().for_each(|x| println!("{}", x));
}

fn read_binaries(n: usize) -> Vec<String> {
    (0..n).map(|_| read!()).collect()
}

fn acm_team(binaries: &[String]) -> [usize; 2] {
    let mut max_subjects: usize = 0;
    let mut teams_with_max: usize = 0;

    for (i, b1) in binaries[..binaries.len() - 1].iter().enumerate() {
        for b2 in &binaries[i + 1..] {
            let known_subjects: usize = count_subjects_known_by_2_teams(b1, b2);

            if known_subjects > max_subjects {
                max_subjects = known_subjects;
                teams_with_max = 1;
            } else if known_subjects == max_subjects {
                teams_with_max += 1;
            }
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
