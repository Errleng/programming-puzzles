import strutils
import algorithm

proc print(things: varargs[string, `$`]) =
    for thing in things:
         stdout.write thing, " "
    stdout.write '\n'
    stdout.flushFile()

let line = readLine(stdin).split(' ')
let n = line[0].parseInt
let l = line[1].parseInt
var words = readLine(stdin).split(' ')
words = words[1..<words.len]
for i in 1..<n:
    let s = readLine(stdin).split(' ')
    let a = s[0].parseInt
    var old_words = words
    for word in old_words:
        for ch in s[1..<s.len]:
            var new_word = word & ch
            if word.len < l:
                words.add(new_word)
words.sort(system.cmp)
for word in words:
    echo word
let (a,b) = (1, 5)
print a, b