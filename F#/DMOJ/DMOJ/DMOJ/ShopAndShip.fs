module ShopAndShip
open Util

let setEdges (graph : int[,]) (esInp : (int * int * int)[]) =
    esInp |> Array.map (fun (a, b, c) ->
        Array2D.set graph a b c
        Array2D.set graph b a c)
        |> ignore

let runShopAndShip () =
    let INF = 0x3f3f3f3f
    let N = readInt ()
    let T = readInt ()
    let edges = readTriples T
    let K = readInt ()
    let shops = readPairs K
    let D = readInt ()

    let graph : int[,] = Array2D.create (N+1) (N+1) INF
    setEdges graph edges
    let dist = Array.create (N+1) INF
    let visited : bool[] = Array.zeroCreate (N+1)
    dist.[D] <- 0
    let mutable cont = true
    while cont do
        let mutable u = -1
        let mutable min = INF
        for i in 1..N do
            if not visited.[i] && dist.[i] < min
            then min <- dist.[i]
                 u <- i
        cont <- u <> -1
        if cont
        then
            visited.[u] <- true
            for i in 1..N do
                if not visited.[i] && graph.[u, i] + dist.[u] < dist.[i]
                then dist.[i] <- graph.[u, i] + dist.[u]
    let mutable ans = INF
    for i in 0..K-1 do
        ans <- if (ans > dist.[fst shops.[i]] + snd shops.[i])
               then dist.[fst shops.[i]] + snd shops.[i]
               else ans
    printfn "%i" ans