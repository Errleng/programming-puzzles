import sys

def SolveWordWrap(lengths, width):
    n = len(lengths)
    extra_spaces = [[0 for i in range(n+1)] for i in range(n+1)] # Count of extra spaces in a line with words[i] to words[j]
    line_costs = [[0 for i in range(n+1)] for i in range(n+1)] # Value of costs of lines from words[i] to words[j]
    word_costs = [0 for i in range(n+1)] # Optimal cost for arranging words[1] to words[j]
    
    for i in range(1, n+1):
        extra_spaces[i][i] = width - lengths[i-1]
        for j in range(i+1, n+1):
            extra_spaces[i][j] = extra_spaces[i][j-1] - lengths[j-1] - 1 # Extra 1 space used for whitespace between words

    for i in range(len(extra_spaces)):
        for j in range(len(extra_spaces)):
            print(extra_spaces[i][j], end=" ")
        print()
    print()

    for i in range(1, n+1):
        for j in range(i, n+1):
            if extra_spaces[i][j] < 0:
                line_costs[i][j] = sys.maxsize # If extra_spaces[i][j] is negative, cost is INF because it is not a possible solution
            elif j == n and extra_spaces[i][j] >= 0:
                line_costs[i][j] = 0 # Last place is line_costs[i][j]. Set to 0 because it is only one word
            else:
                line_costs[i][j] = extra_spaces[i][j] ** 3 # Cost is (amount of extra spaces)^3

    for row in line_costs:
        for val in row:
            if val == sys.maxsize:
                print("I", end=" ")
            else:
                print(val, end=" ")
        print()
    print()

    optimal_lines = [0 for i in range(n+1)]

    word_costs[0] = 0
    for j in range(1, n+1):
        word_costs[j] = sys.maxsize
        for i in range(1, j+1): # Checks from [1][j] to [j+1][j]
            if word_costs[i-1] != sys.maxsize and line_costs[i][j] != sys.maxsize and (word_costs[i-1] + line_costs[i][j] < word_costs[j]):
                word_costs[j] = word_costs[i-1] + line_costs[i][j] # Update with minimum cost
                optimal_lines[j] = i

    for val in word_costs:
        if val == sys.maxsize:
            print("I", end=" ")
        else:
            print(val, end=" ")
    print('\n')

    def PrintOptimalLines(optimal_lines, x):
        if optimal_lines[x] == 1:
            y = 1
        else:
            y = PrintOptimalLines(optimal_lines, optimal_lines[x] - 1) + 1
        print("Line %d words %d to %d" % (y, optimal_lines[x], x))
        return y

    PrintOptimalLines(optimal_lines, n)

def LineBreak(lengths, width):
    n = len(lengths)
    length_sum = [[0 for i in range(n+1)] for j in range(n+1)]
    break_index = [0 for i in range(n+1)]
    costs = [0 for i in range(n+1)]

    for i in range(1, n+1):
        length_sum[i][i] = width - lengths[i]
        for j in range(i, n+1):
            length_sum[i][j] = length_sum[i][j-1] - lengths[j]

    for row in length_sum:
        for val in row:
            print(val, end=" ")
        print()
    print()

word_lengths = [3, 2, 2, 5]
line_width = 6
LineBreak(word_lengths, line_width)