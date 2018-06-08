import sys

stdinput = sys.stdin
input_file = open("input.txt", "r")
sys.stdin = input_file


def main():
    golf_distance = int(input())
    golf_clubs = int(input())
    club_distances = []
    for i in range(golf_clubs):
        club_distances.append(int(input()))
    memo = [sys.maxsize for x in range(golf_distance + 1)]
    answer = recursion_golf(golf_distance, club_distances, memo)
    if answer == sys.maxsize:
        print("Roberta acknowledges defeat.")
    else:
        print("Roberta wins in", answer, "strokes.")


def recursion_golf(distance, dists, memo):
    res = sys.maxsize
    if distance == 0: # Base case: 0 strikes
        return 0
    elif memo[distance] != sys.maxsize:
        return memo[distance]
    for i in range(len(dists)):
        if distance >= dists[i]:
            res = min(res, recursion_golf(distance - dists[i], dists, memo) + 1) # Add 1 to strike count
    memo[distance] = res
    return res


main()
input_file.close()
