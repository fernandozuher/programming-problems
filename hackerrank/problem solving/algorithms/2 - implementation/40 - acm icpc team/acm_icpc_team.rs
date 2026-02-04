// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let _: usize = read!();
    let binaries: Vec<Vec<u8>> = read_binaries(n);
    let [max_subjects, teams_with_max] = acm_team(&binaries);
    println!("{}", max_subjects);
    println!("{}", teams_with_max);
}

fn read_binaries(n: usize) -> Vec<Vec<u8>> {
    (0..n)
        .map(|_| {
            let s: String = read!();
            s.into_bytes()
        })
        .collect()
}

fn acm_team(binaries: &[Vec<u8>]) -> [usize; 2] {
    let mut max_subjects: usize = 0;
    let mut teams_with_max: usize = 0;

    for i in 0..binaries.len() {
        for j in (i + 1)..binaries.len() {
            let known_subjects: usize = count_subjects_known_by_2_teams(&binaries[i], &binaries[j]);

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

fn count_subjects_known_by_2_teams(a: &[u8], b: &[u8]) -> usize {
    a.iter()
        .zip(b.iter())
        .filter(|(&ac, &bc)| ac == b'1' || bc == b'1')
        .count()
}
