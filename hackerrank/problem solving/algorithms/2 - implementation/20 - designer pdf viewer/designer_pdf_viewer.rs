// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

use text_io::read;

fn main() {
    let letters_heights: Vec<usize> = read_line();
    let word: String = read!();
    println!("{}", designer_pdf_viewer(&letters_heights, &word));
}

fn read_line() -> Vec<usize> {
    let mut line: String = read!("{}\n");
    return line.split(' ').map(|s| s.parse().unwrap()).collect();
}

fn designer_pdf_viewer(letters_heights: &Vec<usize>, word: &String) -> usize {
    let mut max_height = 0;

    for letter in word.chars() {
        let letter_index: usize = (letter as usize) - ('a' as usize);
        let letter_height: usize = letters_heights[letter_index];

        if max_height < letter_height {
            max_height = letter_height;
        }
    }

    let area: usize = max_height * word.len();
    return area;
}
