import sys
import time

sys.stdin = open("input.txt", 'r')

start = time.time()
fence_length, fence_heights = 0, 0
planks = [0 for _ in range(2001)]
board_lengths = [0 for _ in range(4001)]

N = int(input())

for i in input().split():
	planks[int(i)] += 1

for j in range(2001):
	for k in range(j, 2001):
		if board_lengths[j + k] != 0:
			print(j, k, board_lengths[j + k])
		if j == k:
			board_lengths[j + k] += planks[j] // 2
		else:
			board_lengths[j + k] += min(planks[j], planks[k])

for i in range(len(board_lengths)):
	if fence_length == board_lengths[i]:
		fence_heights += 1
	elif board_lengths[i]:
		fence_length = board_lengths[i]
		fence_heights = 1

print(fence_length, fence_heights)
print(time.time() - start)
