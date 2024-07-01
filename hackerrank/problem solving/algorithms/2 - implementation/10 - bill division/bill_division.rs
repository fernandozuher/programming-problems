// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut data = Input {
        item_anna_didnt_consume: read!(),
        cost_of_each_meal: read_int_array(n),
        brian_charged_anna: read!(),
    };

    let brian_overcharged_anna = bon_appetit(&data);
    print_output(brian_overcharged_anna);
}

    struct Input {
        item_anna_didnt_consume: i32,
        cost_of_each_meal: Vec<i32>,
        brian_charged_anna: i32,
    }

    fn read_int_array(n: usize) -> Vec<i32> {
        return (0..n).map(|_| read!()).collect();
    }

    fn bon_appetit(data: &Input) -> i32 {
        let anna_cost = calculate_anna_cost(data);
        return how_much_brian_overcharged_anna(data.brian_charged_anna, anna_cost);
    }

        fn calculate_anna_cost(data: &Input) -> i32 {
            let sum: i32 = data.cost_of_each_meal.iter().sum();
            return (sum - data.cost_of_each_meal[data.item_anna_didnt_consume as usize]) / 2;
        }

        fn how_much_brian_overcharged_anna(brian_charged_anna: i32, anna_cost: i32) -> i32 {
            if anna_cost != brian_charged_anna {
                brian_charged_anna - anna_cost
            } else {
                0
            }
        }

    fn print_output(charged: i32) {
        if charged > 0 {
            println!("{}", charged);
        } else {
            println!("Bon Appetit");
        }
    }
