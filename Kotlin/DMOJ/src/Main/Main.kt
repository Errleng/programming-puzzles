package main

import java.io.FileInputStream

fun main(args: Array<String>) {
    System.setIn(FileInputStream("input.txt"))
    val fs = FastScanner(System.`in`)
    var current = aplusb()
    current.solve(fs)
}