import sys
input = sys.stdin.readline

def diff(a, b):
    return (a[0] - b[0], a[1] - b[1])

def mult(a, b):
    return (a[0] * b[1]) - (a[1] * b[0])

def eq(a, b):
    return a[0] == b[0] and a[1] == b[1]

def intersects(a, b):
    co_x = diff(a[1], a[0])
    co_y = diff(b[1], b[0])

    above = mult(diff(b[0], a[0]), co_x)
    below = mult(co_x, co_y)

    if above == 0 and below == 0:
        if eq(a[0], b[0]) or eq(a[0], b[1]) or eq(a[1], b[0]) or eq(a[1], b[1]):
            return True
        x_ov = [(b[0][0] - a[0][0] < 0), (b[0][0] - a[1][0] < 0),
                        (b[1][0] - a[0][0] < 0), (b[1][0] - a[1][0] < 0)];
        y_ov = [(b[0][1] - a[0][1] < 0), (b[0][1] - a[1][1] < 0),
                        (b[1][1] - a[0][1] < 0), (b[1][1] - a[1][1] < 0)];
        return x_ov.count(x_ov[0]) != len(x_ov) or y_ov.count(y_ov[0]) != len(y_ov)
    elif below == 0:
        return False
    x_slr = above / below
    y_slr = mult(diff(b[0], a[0]), co_y) / below
    return x_slr >= 0 and x_slr <= 1 and y_slr >= 0 and y_slr <= 1

los = list(map(int, input().split()))
los = ((los[0], los[1]), (los[2], los[3]))
N = int(input())
ans = 0
for i in range(N):
    ps = list(map(int, input().split()))[1:]
    ls = []
    for j in range(0, len(ps) - 3, 2):
        ls.append(((ps[j], ps[j+1]), (ps[j+2], ps[j+3])))
    ls.append((ls[-1][1], ls[0][0]))
    for j in range(len(ls)):
        if intersects(los, ls[j]):
            ans += 1
            break
print(ans)