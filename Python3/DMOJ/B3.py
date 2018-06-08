N = int(input())

complexities = []

for i in range(N):
    input_line = input().split()
    length = int(input_line[0])
    sequence = input_line[1]
    recurrence = ""
    for j in range(1, len(sequence)):
        subsequence = sequence[:j]
        if length % len(subsequence) == 0 and sequence[len(subsequence):len(subsequence)*2] == subsequence:
            recurrence = subsequence
            break
    largest_recurrence = ""
    for j in range(int(sequence.count(recurrence)/2)):
        largest_recurrence = largest_recurrence + recurrence
    if sequence.count(largest_recurrence) > 1:
        complexities.append(len(largest_recurrence)/sequence.count(largest_recurrence))
    else:
        complexities.append(len(largest_recurrence))
print(max(complexities))