// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

use counter::Counter;

fn main() {
    let mut n: usize = text_io::read!();
    let strings: Vec<String> = read_lines(n);
    let strings_to_counts = strings.iter().collect::<Counter<_>>();

    n = text_io::read!();
    let queries: Vec<String> = read_lines(n);

    counts_from(strings_to_counts, &queries)
        .iter()
        .for_each(|x| println!("{}", x))
}

fn read_lines(n: usize) -> Vec<String> {
    (0..n).map(|_| text_io::read!()).collect()
}

// n: length of queries
// maxQueryStringLength: 20
// T: O(n * maxQueryStringLength) = O(n * 20) = O(n)
// S: O(n) extra space
fn counts_from(freq_map: Counter<&String>, queries: &[String]) -> Vec<usize> {
    queries.iter().map(|q| freq_map[q]).collect()
}
