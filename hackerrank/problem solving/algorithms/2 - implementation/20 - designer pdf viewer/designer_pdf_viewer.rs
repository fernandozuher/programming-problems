// Source: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

use std::io::{self, BufRead};


fn main() {
    let input_line1 = read_line_as_vec_i32();
    let input_line2 = read_line_as_string();

    let result = designerPdfViewer(&input_line1, input_line2);
    println!("{}", result);
}

    fn read_line_as_vec_i32() -> Vec<i32> {
        let stdin = io::stdin();

        let input_line: Vec<i32> = stdin.lock()
          .lines().next().unwrap().unwrap()
          .trim().split(' ')
          .map(|s| s.parse().unwrap())
          .collect();

        return input_line;
    }

    fn read_line_as_string() -> String {
        let stdin = io::stdin();
        let mut input_line = String::new();
        stdin.read_line(&mut input_line);
        return input_line;
    }

    fn designerPdfViewer(lettersHeights: &Vec<i32>, word: String) -> i32 {
        let mut max_height = 0;

        for letter in word.chars() {
            let letter_index: usize = ((letter as i32) - ('a' as i32)) as usize;
            let letter_height: i32 = lettersHeights[letter_index];

            if max_height < letter_height {
                max_height = letter_height;
            }
        }

        let area: i32 = max_height * (word.len() as i32);
        return area;
    }
