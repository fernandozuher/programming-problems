// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let n_queries: usize = read!();

    let mut array: Vec<Vec<i32>> = vec![Vec::new(); n];
    let mut answers: Vec<i32> = Vec::new();
    let mut last_answer: i32 = 0;

    for _ in 0..n_queries {
        let type_i: i32 = read!();
        let x: i32 = read!();
        let y: i32 = read!();

        let index: usize = (x ^ last_answer) as usize % n as usize;

        if type_i == 1 {
            array[index].push(y)
        } else {
            let j: usize = (y as usize) % array[index].len();
            last_answer = array[index][j];
            answers.push(last_answer);
        }
    }

    answers.iter().for_each(|el| println!("{}", el));
}
