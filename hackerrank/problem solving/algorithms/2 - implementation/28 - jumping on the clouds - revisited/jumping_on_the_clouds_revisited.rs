// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

use std::io::{stdin, BufRead};
extern crate text_io;


fn main() {
    let mut array: Vec<i32> = read_an_array();
    let _size_array: i32 = *array.first().unwrap();
    let jump_length: i32 = *array.last().unwrap();
    array = read_an_array();

    let energy: i32 = jumping_on_clouds(array, jump_length);
    println!("{}", energy);
}

    fn read_an_array() -> Vec<i32> {
        let array: Vec<i32> = stdin().lock()
                              .lines().next().unwrap().unwrap()
                              .trim().split(' ')
                              .map(|s| s.parse().unwrap())
                              .collect();
        return array;
    }

    fn jumping_on_clouds(array: Vec<i32>, jump_length: i32) -> i32 {
        let mut energy: i32 = 100;
        let mut cloud_index: usize = 0;

        loop {
            energy -= spent_energy_according_to_type_of_cloud(array[cloud_index]);
            cloud_index = generate_new_cloud_index(cloud_index, array.len(), jump_length);
            if is_cloud_index_back_to_first_cloud(cloud_index) {
                break;
            }
        }

        return energy
    }

        fn spent_energy_according_to_type_of_cloud(cloud_type: i32) -> i32 {
            return if cloud_type == 0 {1} else {3};
        }

        fn generate_new_cloud_index(cloud_index: usize, size_array: usize, jump_length: i32) -> usize {
            return (cloud_index + (jump_length as usize)) % size_array;
        }

        fn is_cloud_index_back_to_first_cloud(cloud_index: usize) -> bool {
            return cloud_index == 0;
        }
