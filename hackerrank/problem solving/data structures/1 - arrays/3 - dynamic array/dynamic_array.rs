// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

use text_io::read;

fn main() {
    let size_arr: usize = read!();
    let n_queries: usize = read!();
    for x in handle_queries(size_arr, n_queries) {
        println!("{}", x);
    }
}

// T: O(n_queries)
// S: O(n + n_queries) extra space
fn handle_queries(n: usize, n_queries: usize) -> Vec<usize> {
    let mut arr: Vec<Vec<usize>> = vec![Vec::new(); n];
    let mut answers: Vec<usize> = Vec::new();
    let mut last_answer: usize = 0;

    for _ in 0..n_queries {
        let type_i: usize = read!();
        let x: usize = read!();
        let y: usize = read!();

        let index: usize = (x ^ last_answer) % n;

        if type_i == 1 {
            arr[index].push(y)
        } else {
            let j: usize = y % arr[index].len();
            last_answer = arr[index][j];
            answers.push(last_answer);
        }
    }

    answers
}
