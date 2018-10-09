import sequtils, strutils

proc readInt(): int =
    readLIne(stdin).parseInt

proc readInts(): seq[int] =
    readLine(stdin).split(" ").map(parseInt)

var N = readInt()

var numbers = newSeq[int]()
for _ in 1..N:
    numbers = concat(numbers, readInts())

var first = true
for num in numbers:
    if first:
        stdout.write(num)
        first = false
    else:
        stdout.write(" ", num)
