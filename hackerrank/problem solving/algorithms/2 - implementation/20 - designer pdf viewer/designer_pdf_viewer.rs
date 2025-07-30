// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

use std::cmp;
use text_io::read;

fn main() {
    const N: usize = 26;
    let letters_heights: Vec<usize> = read_numbers(N);
    let word: String = read!();
    println!("{}", designer_pdf_viewer(&letters_heights, &word));
}

fn read_numbers(n: usize) -> Vec<usize> {
    (0..n).map(|_| read!()).collect()
}

fn designer_pdf_viewer(letters_heights: &[usize], word: &str) -> usize {
    word.chars()
        .map(|c| letters_heights[(c as usize) - ('a' as usize)])
        .max()
        .unwrap_or(0) * word.len()
}
