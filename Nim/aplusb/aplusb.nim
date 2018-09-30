import macros
import sequtils
import strutils

macro `..=`*(lhs: untyped, rhs: tuple|seq|array): auto =
  # Check that the lhs is a tuple of identifiers.
  expectKind(lhs, nnkPar)
  for i in 0..len(lhs)-1:
    expectKind(lhs[i], nnkIdent)
  # Result is a statement list starting with an
  # assignment to a tmp variable of rhs.
  let t = genSym()
  result = newStmtList(quote do:
    let `t` = `rhs`)
  # assign each component to the corresponding
  # variable.
  for i in 0..len(lhs)-1:
    let v = lhs[i]
    # skip assignments to _.
    if $v.toStrLit != "_":
      result.add(quote do:
        `v` = `t`[`i`])

macro headAux(count: int, rhs: seq|array|tuple): auto =
  let t = genSym()
  result = quote do:
    let `t` = `rhs`
    ()
  for i in 0..count.intVal-1:
    result[1].add(quote do:
      `t`[`i`])

template head*(count: static[int], rhs: untyped): auto =
  # We need to redirect this through a template because
  # of a bug in the current Nim compiler when using
  # static[int] with macros.
  headAux(count, rhs)

proc nextInt() : int = 
    return readLine(stdin).parseInt

proc nextIntLine() : seq[int] =
    return readLine(stdin).split(" ").map(parseInt)

var N = nextInt()
for i in 1..N:
    var a, b : int
    (a, b) ..= nextIntLine()
    echo a + b
