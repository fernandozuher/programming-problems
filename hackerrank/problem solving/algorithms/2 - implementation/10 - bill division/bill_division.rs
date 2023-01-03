// Source: https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

use std::io::{self, BufRead};

fn main() {
    let input1 = read_line_as_vec_i32();
    let item_anna_didnt_consume = input1[1] as usize;

    let cost_of_each_meal = read_line_as_vec_i32();
    let brian_charged_anna = read_line_as_vec_i32();

    let result = bon_appetit(&cost_of_each_meal, item_anna_didnt_consume, brian_charged_anna[0]);
    println!("{}", result);
}

    fn read_line_as_vec_i32() -> Vec<i32> {
        let stdin = io::stdin();
        
        let numbers: Vec<i32> = stdin.lock()
          .lines().next().unwrap().unwrap()
          .trim().split(' ')
          .map(|s| s.parse().unwrap())
          .collect();

        return numbers;
    }

    fn bon_appetit(cost_of_each_meal: &Vec<i32>, item_anna_didnt_consume: usize, brian_charged_anna: i32) -> String {
        let anna_cost = calculate_anna_cost(cost_of_each_meal, item_anna_didnt_consume);
        let result = check_if_brian_overcharged_anna(brian_charged_anna, anna_cost);
        return result;
    }

        fn calculate_anna_cost(cost_of_each_meal: &Vec<i32>, item_anna_didnt_consume: usize) -> i32 {
            let sum: i32 = cost_of_each_meal.iter().sum();
            let anna_cost = (sum - cost_of_each_meal[item_anna_didnt_consume]) / 2;
            return anna_cost;
        }

        fn check_if_brian_overcharged_anna(brian_charged_anna: i32, anna_cost: i32) -> String {
            if anna_cost == brian_charged_anna {
                return "Bon Appetit".to_string();
            }
            else {
                let brian_overcharged_ana = brian_charged_anna - anna_cost;
                return brian_overcharged_ana.to_string();
            }
        }
