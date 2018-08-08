module Util
open System
open System.IO
open System.Runtime.InteropServices

let reader = new StreamReader(Console.OpenStandardInput())
let readInt () = reader.ReadLine() |> int

let readPairs n = Array.init n (fun x ->
    match reader.ReadLine().Split(' ') with
    [|a; b|] -> int a, int b)

let readTriples n = Array.init n (fun x -> 
    match reader.ReadLine().Split(' ') with
    [|a; b; c|] -> int a, int b, int c)