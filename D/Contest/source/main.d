module main;

import std.datetime.stopwatch;
import std.stdio;

// Current: Repetitivity


void solve() {
	string S;
	S = readln();
	writeln(S);
}

void main(string[] args) {
    stdin.reopen("../input.txt", "r");

    writeln(readln());

    auto timer = benchmark!(solve)(1);
    auto resTime = timer[0];
}
