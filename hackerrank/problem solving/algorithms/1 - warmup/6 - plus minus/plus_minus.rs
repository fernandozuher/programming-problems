use std::io::{self, BufRead};

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

fn plusMinus(arr: &[i32]) {
    let mut positiveQuantity: i32 = 0;
    let mut negativeQuantity: i32 = 0;
    let mut zeroQuantity: i32 = 0;

    for number in arr {
        if number > &0 {
            positiveQuantity += 1;
        }
        else if number < &0 {
            negativeQuantity += 1;
        }
        else {
            zeroQuantity += 1;
        }
    }

    let n = arr.len() as f32;
    let positiveValuesProportion = (positiveQuantity as f32) / n;
    let negativeValuesProportion = (negativeQuantity as f32) / n;
    let zeroValuesProportion = (zeroQuantity as f32) / n;
    
    println!("{:.6}", positiveValuesProportion);
    println!("{:.6}", negativeValuesProportion);
    println!("{:.6}", zeroValuesProportion);
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let n = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

    let arr: Vec<i32> = stdin_iterator.next().unwrap().unwrap()
        .trim_end()
        .split(' ')
        .map(|s| s.to_string().parse::<i32>().unwrap())
        .collect();

    plusMinus(&arr);
}
