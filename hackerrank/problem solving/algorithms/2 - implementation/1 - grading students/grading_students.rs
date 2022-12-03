use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write};

/*
 * Complete the 'grading_students' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

fn is_zero_remainder(grade: i32) -> bool {
    return grade % 5 == 0;
}

fn grading_students(grades: &[i32]) -> Vec<i32> {
    let N: usize = grades.len();
    let mut new_grades: Vec<i32> = Vec::with_capacity(N);
    unsafe { new_grades.set_len(N) };
    let min_grade: i32 = 38;

    for i in 0..N {
        if grades[i] < min_grade || is_zero_remainder(grades[i]) {
            new_grades[i] = grades[i];
        } else {
            let quocient: i32 = grades[i] / 5;
            let next_multiple_5: i32 = (quocient + 1) * 5;
            let difference: i32 = next_multiple_5 - grades[i];
            
            let mut result: i32;
            if difference < 3 {
                result = next_multiple_5;
            } else {
                result = grades[i];
            }

            new_grades[i] = result;
        }
    }
    return new_grades;
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();

    let grades_count = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

    let mut grades: Vec<i32> = Vec::with_capacity(grades_count as usize);

    for _ in 0..grades_count {
        let grades_item = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();
        grades.push(grades_item);
    }

    let result = grading_students(&grades);

    for i in 0..result.len() {
        write!(&mut fptr, "{}", result[i]).ok();

        if i != result.len() - 1 {
            writeln!(&mut fptr).ok();
        }
    }

    writeln!(&mut fptr).ok();
}
