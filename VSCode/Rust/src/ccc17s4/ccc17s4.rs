#[macro_use] extern crate dmoj;
use std::cmp::Ordering;

pub struct BiEdge {
    pub u: u32,
    pub v: u32,
    pub w: i32,
}

impl BiEdge {
    pub fn new(a: u32, b: u32, weight: i32) -> BiEdge {
        BiEdge {
            u: a,
            v: b,
            w: weight,
        }
    }
}

#[derive(Clone)]
pub struct WEdge {
    pub u: u32,
    pub w: i32,
}

impl WEdge {
    pub fn new(node: u32, weight: i32) -> WEdge {
        WEdge {
            u: node,
            w: weight,
        }
    }
}

pub struct Graph {
    pub V: usize,
    pub cont: Vec<Vec<WEdge>>,
}

impl Graph {
    pub fn new(vertices: usize) -> Graph {
        Graph {
            V: vertices,
            cont: vec![Vec::new(); vertices],
        }
    }

    pub fn add_weighted_edge(&mut self, src: u32, dst: u32, weight: i32) {
        let w_edge = WEdge::new(dst, weight);
        self.cont[src as usize].push(w_edge);
    }
}

pub struct Disjoint {
    pub size: usize,
    pub cont: Vec<u32>,
}

impl Disjoint {
    pub fn new(length: usize) -> Disjoint {
        Disjoint {
            size: length,
            cont: (0..length as u32).collect(),
        }
    }

    pub fn find(&mut self, mut a: u32) -> u32 {
        let mut index = a as usize;
        while a != self.cont[index] {
            self.cont[index] = self.cont[self.cont[index] as usize];
            a = self.cont[index];
            index = a as usize;
        }
        a
    }

    pub fn union(&mut self, a: u32, b: u32) -> bool {
        let a_root = self.find(a);
        let b_root = self.find(b);
        if a_root != b_root {
            self.cont[a_root as usize] = b_root;
            true
        } else {
            false
        }
    }
}

#[derive(Debug, Eq, PartialEq, PartialOrd)]
pub struct Pipe {
    u: u32,
    v: u32,
    w: i32,
    c: bool,
}

impl Pipe {
    pub fn new(a: u32, b: u32, weight: i32, flow: bool) -> Pipe {
        Pipe {
            u: a,
            v: b,
            w: weight,
            c: flow,
        }
    }
}

impl Ord for Pipe {
    fn cmp(&self, other: &Pipe) -> Ordering {
        if self.w == other.w {
            self.c.cmp(&other.c)
        } else {
            self.w.cmp(&other.w)
        }
    }
}

fn main() {
    let (N, M, D) = (scan!(usize), scan!(usize), scan!(usize));

    let mut disjoint = Disjoint::new(N);

    let mut edges = Vec::new();

    for i in 0..M {
        let (a, b, c) = (scan!(u32) - 1, scan!(u32) - 1, scan!(i32));
        if i < N - 1 {
            let pipe = Pipe::new(a, b, c, false);
            edges.push(pipe);
        } else {
            let pipe = Pipe::new(a, b, c, true);
            edges.push(pipe);
        }
    }

    edges.sort_by(|a, b| a.cmp(b));

    let mut days = 0;
    let mut cnt = 0;
    let mut max_w = 0;
    let mut index = 0;
    for i in 0..M {
        index += 1;
        if cnt == N-1 {
            break;
        }
        let e = &edges[i];
        if disjoint.union(e.u, e.v) {
            cnt += 1;
            max_w = e.w;
            if e.c {
                days += 1;
            }
        }
    }
    if edges[index - 1].c {
        disjoint = Disjoint::new(N);
        for e in edges {
            if disjoint.find(e.u) != disjoint.find(e.v) {
                if e.w < max_w || (e.w == max_w && e.c) {
                    disjoint.union(e.u, e.v);
                } else if !e.c && e.w <= D as i32 {
                    days -= 1;
                    break;
                }
            }
        }
    }
    println!("{}", days);
}