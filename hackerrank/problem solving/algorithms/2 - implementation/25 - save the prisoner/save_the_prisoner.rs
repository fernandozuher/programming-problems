// Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

#[macro_use]
extern crate text_io;


fn main() {
    let n_test_cases: usize = read!();
    let prisoners_chair_number_to_warn: Vec<i32> = read_test_cases_and_save_the_prisoners(n_test_cases);
    print_results(prisoners_chair_number_to_warn);
}

    fn read_test_cases_and_save_the_prisoners(n_test_cases: usize) -> Vec<i32> {
        let mut prisoners_chair_number_to_warn = Vec::with_capacity(n_test_cases);
        unsafe { prisoners_chair_number_to_warn.set_len(n_test_cases); }

        for i in 0..n_test_cases {
            let test_case: Vec<i32> = read_test_case();
            prisoners_chair_number_to_warn[i] = save_the_prisoner(test_case);
        }

        return prisoners_chair_number_to_warn;
    }

        fn read_test_case() -> Vec<i32> {
            let mut test_case = Vec::new();
            
            test_case.push(read!());
            test_case.push(read!());
            test_case.push(read!());
            
            return test_case;
        }

        fn save_the_prisoner(test_case: Vec<i32>) -> i32 {
            let prisoners: i32 = *test_case.first().unwrap();
            let sweets: i32 = *test_case.get(1).unwrap();
            let chair_number_to_begin: i32 = *test_case.last().unwrap();
            let mut prisoner_chair_number_to_warn: i32 = chair_number_to_begin + (sweets - 1);

            if prisoner_chair_number_to_warn > prisoners {
                prisoner_chair_number_to_warn %= prisoners;

                if prisoner_chair_number_to_warn == 0 {
                    prisoner_chair_number_to_warn = prisoners;
                }
            }

            return prisoner_chair_number_to_warn;
        }

    fn print_results(array: Vec<i32>) {
        array.iter().for_each(|element| println!("{}", element));
    }
