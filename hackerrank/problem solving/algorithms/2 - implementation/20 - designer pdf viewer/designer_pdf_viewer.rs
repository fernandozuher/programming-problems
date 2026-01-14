// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

use text_io::read;

const ALPHABET_SIZE: usize = 26;

fn main() {
    let letters_heights: [usize; ALPHABET_SIZE] = read_input();
    let word: String = read!();
    println!("{}", designer_pdf_viewer(&letters_heights, &word));
}

fn read_input() -> [usize; ALPHABET_SIZE] {
    core::array::from_fn(|_| read!())
}

// n_w: length of string word, no more than 10 letters
// T = O(10) = O(1)
// S = O(1) extra space
fn designer_pdf_viewer(letters_heights: &[usize], word: &str) -> usize {
    word.chars()
        .map(|ch| letters_heights[(ch as usize) - ('a' as usize)])
        .max()
        .unwrap_or(0)
        * word.len()
}
