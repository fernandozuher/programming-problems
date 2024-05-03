// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let beautiful_difference: i32 = read!();
    let array: Vec<i32> = read_int_array(n);
    println!("{}", find_beautiful_triplets(array, beautiful_difference));
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn find_beautiful_triplets(array: Vec<i32>, beautiful_difference: i32) -> i32 {
    let mut n_beautiful_triplets: i32 = 0;

    if array.len() > 2 {
        for i in 0..(array.len() - 2) {
            for j in (i + 1)..(array.len() - 1) {
                let first_difference: i32 = array[j] - array[i];

                if first_difference < beautiful_difference {
                    continue;
                } else if first_difference > beautiful_difference {
                    break;
                }

                for k in (j + 1)..array.len() {
                    let second_difference: i32 = array[k] - array[j];

                    if second_difference == beautiful_difference {
                        n_beautiful_triplets += 1;
                    } else if second_difference > beautiful_difference {
                        break;
                    }
                }
            }
        }
    }

    return n_beautiful_triplets;
}
