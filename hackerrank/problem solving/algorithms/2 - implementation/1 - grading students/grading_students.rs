// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let array: Vec<i32> = read_int_array(n);
    print_int_array(&grading_students(&array));
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn is_zero_remainder(grade: i32) -> bool {
    return grade % 5 == 0;
}

fn grading_students(grades: &Vec<i32>) -> Vec<i32> {
    let n: usize = grades.len();
    let mut new_grades: Vec<i32> = Vec::with_capacity(n);
    unsafe { new_grades.set_len(n) };
    let min_grade: i32 = 38;

    for i in 0..n {
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

fn print_int_array(array: &Vec<i32>) {
    array.iter().for_each(|x| println!("{}", x));
}
