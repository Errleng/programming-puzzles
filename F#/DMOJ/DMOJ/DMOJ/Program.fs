open System
open Util
open ShopAndShip


[<EntryPoint>]
let main argv = 
    let stopwatch = System.Diagnostics.Stopwatch.StartNew()
    runShopAndShip ()
    let endTime = stopwatch.Elapsed.TotalMilliseconds
    printfn "Elapsed ms: %f" endTime
    0
