from string import ascii_uppercase
class DisjointSet():
    def __init__(self, size):
        self.size = size
        self.cont = [i for i in range(self.size)]
        self.rank = [0 for i in range(self.size)]

    def find(self, x):
        if self.cont[x] == x:
            return x
        else:
            xTop = self.find(self.cont[x])
            self.cont[x] = xTop
            return xTop

    def union(self, x, y):
        xTop = self.find(x)
        yTop = self.find(y)

        if self.rank[xTop] < self.rank[yTop]:
            self.cont[xTop] = yTop
        else:
            self.cont[yTop] = xTop
            if self.rank[xTop] == self.rank[yTop]:
                self.rank[xTop] = self.rank[yTop] + 1

num_vertices = int(input())
graph_matrix = []
for i in range(num_vertices):
    graph_matrix.append([int(x) for x in input().split(',')])

for i in range(len(graph_matrix)):
    for j in range(len(graph_matrix[i])):
        print(graph_matrix[i][j], end=" ")
    print()
print()

edges = [(w, i, j) for i, a in enumerate(graph_matrix) for j, w in enumerate(a) if w != -1]
edges.sort()

dj_set = DisjointSet(num_vertices)
unions = []
for i in range(len(edges)):
    w = edges[i][0]
    x = edges[i][1]
    y = edges[i][2]
    if dj_set.find(x) != dj_set.find(y):
        dj_set.union(x, y)
        unions.append(edges[i])

print(sum(e[0] for e in unions))
print(','.join((chr(e[1] + 65)) + (chr(e[2] + 65)) for e in sorted(unions, key=lambda x: x[1])))
