#!/bin/bash
if cargo build --color=always
then
	target/debug/DMOJ < input.txt > output.txt
	printf -- "\n----- OUTPUT BEGINS -----\n"
	cat output.txt
	printf -- "----- OUTPUT ENDS -----\n"
	diff output.txt answer.txt && echo "Output passes answer test" || echo "Output does not match answer"
fi
