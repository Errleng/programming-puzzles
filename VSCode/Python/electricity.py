T = int(input())
for case_num in range(T):
    X, P = [], []
    N = int(input())
    for i in range(N):
        [x, p] = [int(a) for a in input().split()]
        X.append(x)
        P.append(p)
    length = 0
    backs = [0 for i in range(N)]
    fronts = [0 for i in range(N)]
    for i in range(N):
        x, p = X[i], P[i]
        if not p:
            back = i
            while back > 0 and not P[back]:
                back -= 1
            front = i
            while front < N - 1 and not P[front]:
                front += 1
            p_back, p_front = P[back], P[front]
            x_back, x_front = X[back], X[front]
            diff_back, diff_front = abs(x - x_back), abs(x - x_front)
            if p_back and p_front:
                if diff_back < diff_front:
                    fronts[back] = max(fronts[back], diff_back)
                elif diff_front < diff_back:
                    backs[front] = max(backs[front], diff_front)
            elif p_back:
                fronts[back] = max(fronts[back], diff_back)
            elif p_front:
                backs[front] = max(backs[front], diff_front)
                i = front + 1
    for i in range(N):
        length += fronts[i]
        length += backs[i]
    print(length)