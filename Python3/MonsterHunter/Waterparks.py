import time

class Node():
    def __init__(self, data):
        self.data = data
        self.visited = False
        self.children = []
        self.parents = []
        self.depth = None

    def __str__(self):
        return str(self.data)

def top_sort():
    stack = []

    def perform_top_sort(node, stack):
        node.visited = True
        for c in node.children:
            if not c.visited:
                perform_top_sort(c, stack)
        stack.insert(0, node)

    for i in range(len(node_list)):
        if not node_list[i].visited:
            perform_top_sort(node_list[i], stack)
    print("Stack:", [x.data for x in stack])
    for node in stack:
        node.visited = False
    return stack

    # slides = []
    # while True:
    #     input_line = [int(x) for x in input().split()]
    #     # print("Input:", input_line)
    #     if input_line == [0, 0]:
    #         break
    #     else:
    #         if input_line[0] - 1 < len(slides):
    #             slides[input_line[0] - 1].extend(input_line[1:])
    #         else:
    #             slides.append(input_line)
    # slides.append([marked_points])
    # node_list = [Node(None) for x in range(marked_points)]
    # for i in range(len(slides)):
    #     node_list[i].data = slides[i][0]
    #     for j in slides[i][1:]:
    #         node_list[i].children.append(node_list[j-1])
    #         node_list[j-1].parents.append(node_list[i])
    #
    # def compute_paths(start, end):
    #     num_paths = 0
    #     if start == end:
    #         return 1
    #     else:
    #         for p in start.parents:
    #             num_paths += compute_paths(p, end)
    #     return num_paths

def S4_2007_Smartie():
    marked_points = int(input())
    adjacency = [[] for x in range(marked_points)] # 1-way graph
    path_counts = [0 for x in range(marked_points)]

    point = [int(x) for x in input().split()]
    src, dst = point[0], point[1]
    while src != 0 or dst != 0:
        adjacency[src-1].append(dst)
        point = [int(x) for x in input().split()]
        src, dst = point[0], point[1]


    # path_counts[0] = 1
    # for i in range(len(adjacency)):
    #     for j in range(len(adjacency[i])):
    #         path_counts[adjacency[i][j] - 1] += path_counts[i]
    # print(path_counts[-1]

    path_counts[-1] = 1
    print(adjacency)
    for i in range(len(adjacency)-1, -1, -1):
        for j in range(len(adjacency[i])-1, -1, -1):
            path_counts[i] += path_counts[adjacency[i][j]-1]
            print(path_counts)
    print(path_counts[0])

def S4_2007_Original():
    marked_points = int(input())
    path_counts = [0 for x in range(marked_points)]
    nodes = [Node(None) for x in range(marked_points)]
    nodes[-1].data = marked_points
    point = [int(x) for x in input().split()]
    src, dst = point[0], point[1]
    while src != 0 or dst != 0:
        nodes[src-1].data = src
        nodes[src-1].children.append(nodes[dst-1])
        point = [int(x) for x in input().split()]
        src, dst = point[0], point[1]
    path_counts[-1] = 1
    for i in range(len(nodes)-1, -1, -1):
        print(i+1, "src:", path_counts[i], end="| ")
        for j in range(len(nodes[i].children)-1, -1, -1):
            print(j, "dst:", path_counts[nodes[i].children[j].data-1], end=" ")
            path_counts[i] += path_counts[nodes[i].children[j].data-1]
            print("\ni:", i, path_counts[i])
        print("\n" + str(path_counts))
    print(path_counts[0])

start_time = time.time()

S4_2007_Smartie()

end_time = time.time()
print("Took", end_time - start_time, "seconds to run")