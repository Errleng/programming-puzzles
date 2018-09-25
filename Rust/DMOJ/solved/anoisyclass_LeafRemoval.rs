#[macro_use]
extern crate dmoj;

const MAXN: usize = 10_001;

fn main() {
    let N = scan!(usize);
    let M = scan!(usize);
    let mut shut = true;
    let mut friends = [0; MAXN];
    let mut adj = vec![vec![]; MAXN];

    for _ in 0..M {
        let (a, b) = (scan!(usize), scan!(usize));
        friends[a] += 1;
        adj[b].push(a);
    }
    let mut dq: std::collections::VecDeque<usize> = std::collections::VecDeque::new();
    for i in 1..N + 1 {
        if friends[i] == 0 {
            dq.push_back(i);
        }
    }
    let mut count = 0;
    while let Some(cur) = dq.pop_front() {
        count += 1;
        for &i in adj[cur].iter() {
            friends[i] -= 1;
            if friends[i] == 0 {
                dq.push_back(i);
            }
        }
    }
    shut = count == N;
    println!("{}", if shut { "Y" } else { "N" });
}