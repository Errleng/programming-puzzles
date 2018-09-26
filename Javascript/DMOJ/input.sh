#!/bin/bash
if v8dmoj main.js < input.txt > output.txt
then
	printf -- "\n----- OUTPUT BEGINS -----\n"
	cat output.txt
	printf -- "----- OUTPUT ENDS -----\n"
	diff output.txt answer.txt && echo "Output passes answer test" || echo "Output does not match answer"
fi
