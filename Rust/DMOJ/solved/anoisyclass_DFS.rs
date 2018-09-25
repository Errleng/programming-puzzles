#[macro_use] extern crate dmoj;

const MAXN: usize = 10_001;

pub fn dfs(ret: &mut bool, cur: usize, vis: &mut [bool], rec: &mut [bool], adj: &Vec<Vec<usize>>) {
    vis[cur] = true;
    rec[cur] = true;
    for &i in adj[cur].iter() {
        if !vis[i] {
            dfs(ret, i, vis, rec, adj)
        } else if rec[i] {
            *ret = false;
            return;
        }
    }
    rec[cur] = false;
}

fn main() {
    let N = scan!(usize);
    let M = scan!(usize);
    let mut visited = [false; MAXN];
    let mut stack = [false; MAXN];
    let mut adj = vec![vec![]; MAXN];
    let mut shut = true;

    for _ in 0..M {
        let (a, b) = (scan!(usize), scan!(usize));
        adj[a].push(b);
    }
    for i in 0..N {
        if !visited[i] {
            dfs(&mut shut, i, &mut visited, &mut stack, &adj);
            if !shut {
                break;
            }
        }
    }
    println!("{}", if shut {"Y"} else {"N"});
}