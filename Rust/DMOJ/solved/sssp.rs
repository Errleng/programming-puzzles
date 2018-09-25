#[macro_use] extern crate dmoj;

const INF: i32 = 0x3f3f3f3f;
const MAXN: usize = 1001;

#[derive(Copy, Clone, Eq, PartialEq)]
pub struct Edge(pub usize, pub i32);
impl Ord for Edge {
    fn cmp(&self, other: &Edge) -> std::cmp::Ordering {
        other.1.cmp(&self.1).then_with(|| self.0.cmp(&other.0))
    }
}
impl PartialOrd for Edge {
    fn partial_cmp(&self, other: &Edge) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

pub fn dijkstra(start: usize, dist: &mut [i32], adj_list: &mut Vec<Vec<Edge>>) {
    let mut heap: std::collections::binary_heap::BinaryHeap<Edge> = std::collections::binary_heap::BinaryHeap::new();
    dist[start] = 0;
    heap.push(Edge(start, 0));
    while let Some(Edge(u, w)) = heap.pop() {
        if w > dist[u] {
            continue;
        }
        for &Edge(v, c) in adj_list[u].iter() {
            if c != -1 {
                let new_dist = w + c;
                if new_dist < dist[v] {
                    dist[v] = new_dist;
                    heap.push(Edge(v, new_dist));
                }
            }
        }
    }
}

fn main() {
    let (N, M) = (scan!(usize), scan!(usize));
    let mut dist = [INF; MAXN];
    let mut adj: Vec<Vec<Edge>> = vec![vec![]; MAXN];

    for _ in 0..M {
        let (u, v, w) = (scan!(usize), scan!(usize), scan!(i32));
        adj[u].push(Edge(v, w));
        adj[v].push(Edge(u, w));
    }
    dijkstra(1, &mut dist, &mut adj);
    for i in 1..N + 1 {
        println!("{}", if dist[i] == INF {-1} else {dist[i]});
    }
}