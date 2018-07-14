import sys

sys.stdin = open("input.txt", 'r')

r = int(input())
while r != 0:
	pennies = 0
	r_sqr = r * r
	for i in range(r + 1):
		pennies += int((r_sqr - i*i)**0.5)
	pennies = pennies * 4 + 1
	print(pennies)
	r = int(input())
