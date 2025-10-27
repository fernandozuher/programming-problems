// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let grades: Vec<i32> = read_numbers(n);
    let rounded_grades: Vec<i32> = grade_students(&grades);
    rounded_grades.iter().for_each(|x| println!("{}", x));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn grade_students(grades: &[i32]) -> Vec<i32> {
    const MIN_GRADE: i32 = 38;

    grades
        .into_iter()
        .map(|&grade| {
            if grade < MIN_GRADE {
                grade
            } else {
                let next_multiple_5: i32 = (grade / 5 + 1) * 5;
                if next_multiple_5 - grade < 3 {
                    next_multiple_5
                } else {
                    grade
                }
            }
        })
        .collect()
}
