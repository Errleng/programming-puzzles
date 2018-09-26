let N = Number(gets())

for (i = 0; i < N; ++i) {
    print(gets().split(" ").map(Number).reduce((a, b) => a + b, 0))
}
