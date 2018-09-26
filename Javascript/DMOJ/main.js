let s = gets()
let N = Number(gets())
let ans = 0
for (let i = 0; i < s.length; i++) {
    let len = 1;
    let letter = ''
    for (let j = i; j < i + N; j++, len++) {
        if (letter == '') {
            letter = s.charAt(j)
        } else if (letter != s.charAt(j)) {
            break;
        }
        if (len == N) {
            ans++
        }
    }
}
print(ans)
