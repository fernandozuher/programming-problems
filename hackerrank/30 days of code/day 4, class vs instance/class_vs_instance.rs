// https://www.hackerrank.com/challenges/30-class-vs-instance/problem?isFullScreen=true

use text_io::read;

struct Person {
    age: i32,
}

impl Person {
    fn new(mut initial_age: i32) -> Person {
        if initial_age < 0 {
            initial_age = 0;
            println!("Age is not valid, setting age to 0.");
        }
        return Person { age: initial_age };
    }

    fn am_i_old(&self) {
        if self.age < 13 {
            println!("You are young.");
        } else if self.age >= 13 && self.age < 18 {
            println!("You are a teenager.");
        } else {
            println!("You are old.");
        }
    }

    fn year_passes(&mut self) {
        self.age += 1;
    }
}

fn main() {
    let n_tests: i32 = read!();

    for _ in 0..n_tests {
        let age = read!();
        let mut p = Person::new(age);
        p.am_i_old();

        for _ in 0..3 {
            p.year_passes();
        }
        p.am_i_old();

        println!("");
    }
}
