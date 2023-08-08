// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

use std::collections::HashMap;

fn main() {
    let n: i32 = read!();
    let mut phone_book = HashMap::new();

    for _ in 0..n {
        let (name, phone): (String, String);
        scan!("{} {}", name, phone);
        phone_book.insert(name, phone);
    }

    loop {
        let name: String = read!();
        if name == "" {
            break;
        }

        let value = phone_book.get(&name);
        if value != None {
            println!("{}={}", name, value.unwrap());
        } else {
            println!("Not found");
        }
    }
}
