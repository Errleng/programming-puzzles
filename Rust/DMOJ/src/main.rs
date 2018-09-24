#[macro_use] extern crate dmoj;

fn main() {
    let (a, b) = (scan!(i32), scan!(i32));
    println!("{}", (b - a) + b);
}