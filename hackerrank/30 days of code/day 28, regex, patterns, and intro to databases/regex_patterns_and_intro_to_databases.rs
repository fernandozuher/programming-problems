// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

use text_io::{read, scan};

fn main() {
    let n: i32 = read!();
    let mut names: Vec<String> = find_names_with_gmail_domains_emails_from_stdin(n);
    sort_in_place_and_print_names(&mut names);
}

fn find_names_with_gmail_domains_emails_from_stdin(n: i32) -> Vec<String> {
    let mut names: Vec<String> = Vec::new();

    for _ in 0..n {
        let (name, email_id): (String, String);
        scan!("{} {}", name, email_id);
        if email_id.contains("@gmail.com") {
            names.push(name);
        }
    }

    return names;
}

fn sort_in_place_and_print_names(names: &mut Vec<String>) {
    names.sort();
    for x in names {
        println!("{}", x);
    }
}
