// Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

use std::io::{stdin, BufRead};

#[macro_use]
extern crate text_io;


fn main() {
    let mut input: Vec<Vec<i32>> = read_input();
    input = reduce_input_rotations(input);
    input = rotate_input_array(input);
    print_rotated_array_elements_according_to_queries(input);
}

    fn read_input() -> Vec<Vec<i32>> {
        let line: Vec<i32> = read_line_as_vec_i32();
        let array_size: Vec<i32> = vec![*line.first().unwrap(); 1];
        let rotation_count: Vec<i32> = vec![line[1]; 1];
        let queries_size: Vec<i32> = vec![*line.last().unwrap(); 1];

        let array: Vec<i32> = read_line_as_vec_i32();
        let queries: Vec<i32> = read_queries(*queries_size.first().unwrap() as usize);

        let mut input: Vec<Vec<i32>> = vec![array, array_size, rotation_count, queries, queries_size];

        return input;
    }

        fn read_line_as_vec_i32() -> Vec<i32> {
            let array: Vec<i32> = stdin().lock()
                                  .lines().next().unwrap().unwrap()
                                  .trim().split(' ')
                                  .map(|s| s.parse().unwrap())
                                  .collect();
            return array;
        }

        fn read_queries(array_size: usize) -> Vec<i32> {
            let mut array: Vec<i32> = Vec::with_capacity(array_size);
            unsafe { array.set_len(array_size); }

            array.fill_with(|| read!());

            return array;
        }

    fn reduce_input_rotations(mut input: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let array_size = *input[1].first().unwrap();
        let rotation_count: i32 = *input[2].first().unwrap();

        if array_size > 1 {
            input[2][0] = if rotation_count >= array_size {rotation_count % array_size} else {rotation_count};
        }
        else {
            input[2][0] = 0;
        }

        return input;
    }

    fn rotate_input_array(mut input: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let array: &Vec<i32> = &input[0];
        let array_size: usize = *input[1].first().unwrap() as usize;
        let rotation_count: usize = *input[2].first().unwrap() as usize;

        let mut new_array = Vec::with_capacity(array_size);
        unsafe { new_array.set_len(array_size); }

        let mut j = 0;
        for i in (array_size - rotation_count)..array_size {
            new_array[j] = array[i];
            j += 1;
        }

        for i in 0..(array_size - rotation_count) {
            new_array[j] = array[i];
            j += 1;
        }

        input[0] = new_array;
        return input;
    }

    fn print_rotated_array_elements_according_to_queries(input: Vec<Vec<i32>>) {
        let array: &Vec<i32> = &input[0];
        let queries: &Vec<i32> = &input[3];

        queries.iter().for_each(|query| println!("{}", array[*query as usize]));
    }
