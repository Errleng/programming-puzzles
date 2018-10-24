let N = parseInt(gets())

var adj = Array.from({ length: N + 1 }, () => [])
var L = new Array(N + 1).fill(0)
var R = new Array(N + 1).fill(0)
var D = new Array(N + 1).fill(0)
var C = new Array(N + 1).fill(false)

function dFine(cur, prev) {
    adj[cur].forEach(v => {
        if (v != prev) {
            dFine(v, cur)
            let d = L[v] + 1
            if (d > L[cur]) {
                C[v] = true
                R[cur] = L[cur]
                L[cur] = d
            } else if (d > R[cur]) {
                R[cur] = d
            }
        }
    });
    return L[cur]
}

function choose(cur, prev) {
    adj[cur].forEach(v => {
        if (v != prev) {
            if (C[v]) {
                D[v] = 1 + Math.max(D[cur], R[cur])
            } else {
                D[v] = 1 + Math.max(D[cur], L[cur])
            }
            choose(v, cur)
        }
    });
    D[cur] = 1 + Math.max(D[cur], L[cur])
}

for (let i = 0; i < N - 1; i++) {
    let [a, b] = gets().split(" ")
    adj[a].push(b)
    adj[b].push(a)
}

dFine(1, -1)
choose(1, -1)

for (let i = 1; i <= N; i++) {
    print(D[i])
}