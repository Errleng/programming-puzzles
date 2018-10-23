let N = parseInt(gets())

var adj = new Array(N + 1)
var L = new Array(N + 1).fill(0)
var R = new Array(N + 1).fill(0)
var C = new Array(N + 1).fill(0)
var D = new Array(N + 1).fill(0)

function distL(cur, prev) {
    adj[cur].forEach(v => {
        if (v != prev) {
            let res = 1 + distL(v, cur)
            if (res > L[cur]) {
                C[cur] = v
                R[cur] = L[cur]
                L[cur] = res
            } else if (res > R[cur]) {
                R[cur] = res
            }
        }
    });
    return L[cur]
}

function distR(cur, prev) {
    adj[cur].forEach(v => {
        if (v != prev) {
            if (v == C[cur]) {
                D[v] = 1 + Math.max(D[cur], R[cur])
            } else {
                D[v] = 1 + Math.max(D[cur], L[cur])
            }
            distR(v, cur)
        }
    });
    D[cur] = Math.max(D[cur], L[cur]) + 1
}

for (let i = 0; i <= N; i++) {
    adj[i] = []
}

for (let i = 0; i < N - 1; i++) {
    let [a, b] = gets().split(" ")
    adj[a].push(b)
    adj[b].push(a)
}

distL(1, -1)
distR(1, -1)

for (let i = 1; i <= N; i++) {
    print(D[i])
}