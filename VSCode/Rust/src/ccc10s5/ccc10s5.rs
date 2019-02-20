#[macro_use] extern crate dmoj;

fn main() {
    let n = scan!(usize);

    for _ in 0..n {
        println!("{}", scan!(i64) + scan!(i64));
    }
}