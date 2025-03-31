// https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

use text_io::read;

fn main() {
    let mut numbers: Vec<i32> = read_input();
    let n_swaps: usize = bubble_sort(&mut numbers);
    println!("Array is sorted in {} swaps.", n_swaps);
    println!("First Element: {}", numbers[0]);
    println!("Last Element: {}", numbers.last().unwrap());
}

fn read_input() -> Vec<i32> {
    let n: usize = read!();
    (0..n).map(|_| read!()).collect()
}

fn bubble_sort(a: &mut [i32]) -> usize {
    let mut total_swaps: usize = 0;
    let mut end: usize = a.len();

    while end > 0 {
        let (n_swaps, new_end) = sort_slice(&mut a[0..end]);
        total_swaps += n_swaps;
        end = new_end;
    }
    total_swaps
}

fn sort_slice(a: &mut [i32]) -> (usize, usize) {
    let mut n_swaps: usize = 0;
    let mut new_end = 0;

    for i in 0..(a.len() - 1) {
        if a[i] > a[i + 1] {
            a.swap(i, i + 1);
            n_swaps += 1;
            new_end = i + 1;
        }
    }
    (n_swaps, new_end)
}
