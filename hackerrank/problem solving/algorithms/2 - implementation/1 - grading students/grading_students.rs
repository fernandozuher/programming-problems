// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut grades: Vec<i32> = read_numbers(n);
    for x in grading_students(&mut grades) {
        println!("{}", x);
    }
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

// n: length of array grades
// T: O(n)
// S: O(1) extra space
fn grading_students(grades: &mut [i32]) -> &[i32] {
    const MIN_GRADE: i32 = 38;

    for grade in grades.iter_mut() {
        if *grade >= MIN_GRADE {
            let next_multiple_5: i32 = (*grade / 5 + 1) * 5;
            if next_multiple_5 - *grade < 3 {
                *grade = next_multiple_5;
            }
        }
    }

    grades
}