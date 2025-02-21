// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

use std::collections::HashMap;
use text_io::{read, scan};

fn main() {
    let n: i32 = read!();
    let phone_book: HashMap<String, String> = init_phone_book(n);
    query_names(phone_book);
}

fn init_phone_book(n: i32) -> HashMap<String, String> {
    let mut phone_book = HashMap::new();
    for _ in 0..n {
        let (name, phone): (String, String);
        scan!("{} {}", name, phone);
        phone_book.insert(name, phone);
    }
    phone_book
}

fn query_names(phone_book: HashMap<String, String>) {
    loop {
        let name: String = read!();
        if name == "" {
            break;
        }

        let value = phone_book.get(&name);
        if value != None {
            println!("{}={}", name, value);
        } else {
            println!("Not found");
        }
    }
}
