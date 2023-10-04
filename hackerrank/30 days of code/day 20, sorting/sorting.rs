// https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());

    println!("Array is sorted in {} swaps.", bubble_sort(&mut array));
    println!("First Element: {}", array[0]);
    println!("Last Element: {}", array[array.len() - 1]);
}

fn bubble_sort(a: &mut Vec<i32>) -> i32 {
    let mut number_of_swaps: i32 = 0;

    for n in (0..a.len()).rev() {
        for i in 0..n {
            if a[i] > a[i + 1] {
                a.swap(i, i + 1);
                number_of_swaps += 1;
            }
        }

        if number_of_swaps == 0 {
            break;
        }
    }

    return number_of_swaps;
}
