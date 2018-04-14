import time
import os
import sys
import re
import collections
import copy

class Node(object):
    def __init__(self, data, position):
        self.data = data
        self.pos = position
        self.adjacent_nodes = []
        self.parent = None
        self.visited = False

class Trapper(object):
    def __init__(self, map):
        self.passable_tiles = [' ', 'N', 'F', 'P']
        self.maze = [list(x) for x in re.split(r'\n', map) if len(x) > 0]
        print("Maze length:", len(self.maze), "Row length:", len(self.maze[0]))
        print(self.maze)
        self.display_maze = copy.deepcopy(self.maze)
        self.size = len(self.maze)
        self.visited = [[False for x in range(self.size)] for y in range(self.size)]
        self.nodes = []
        self.paths = []

    def PrintMaze(self):
        maze_string = ""
        for row in range(len(self.maze)):
            for col in range(len(self.maze[row])):
                maze_string += str(self.maze[row][col])
            maze_string += "\n"
        print(maze_string)
    
    def PrintDisplay(self):
        display_string = ""
        for row in range(len(self.display_maze)):
            for col in range(len(self.display_maze[row])):
                display_string += str(self.display_maze[row][col])
            display_string += "\n"
        print(display_string)
    
    def ChangeTile(self, tile_pos, symbol):
        self.display_maze[tile_pos[0]][tile_pos[1]] = symbol

    def IsPassable(self, position):
        if (position[0] >= 0 and position[0] < self.size and position[1] >= 0 and position[1] < self.size):
            return self.maze[position[0]][position[1]] in self.passable_tiles
    
    def IsTileVisited(self, position):
        if (position[0] >= 0 and position[0] < self.size and position[1] >= 0 and position[1] < self.size):
            is_visited = self.visited[position[0]][position[1]]
            return is_visited

    def ResetVisited(self):
        for i in range(len(self.visited)):
            for j in range(len(self.visited[i])):
                self.visited[i][j] = False
        for i in range(len(self.nodes)):
            self.nodes[i].visited = False
    
    def ResetDisplay(self):
        for i in range(len(self.maze)):
            for j in range(len(self.maze[i])):
                self.display_maze[i][j] = self.maze[i][j]
    
    def DoStuff(self):
        monster_pos = (-1, -1)
        food_pos = (-1, -1)
        for i in range(len(self.maze)):
            for j in range(len(self.maze[i])):
                if self.maze[i][j] == 'F':
                    food_pos = (i, j)
                elif self.maze[i][j] == 'N':
                    monster_pos = (i, j)
        print("Monster starts at", monster_pos[0] + 1, monster_pos[1] + 1)
        self.MapOut(monster_pos)
        time.sleep(2)
        # self.BFS(self.nodes[0])

        self.ResetVisited()
        self.ResetDisplay()
        # self.DFS_Recursive(self.nodes[0], [])
        self.DFS_Simple(self.nodes[0])

        self.ResetVisited()
        self.ResetDisplay()
        trapped_paths = []
        traps_in_paths = []
        for i in range(len(self.paths)):
            trapped = False
            traps = []
            for j in range(len(self.paths[i])):
                self.ChangeTile(self.paths[i][j].pos, '%')
                if self.maze[self.paths[i][j].pos[0]][self.paths[i][j].pos[1]] == 'P':
                    trapped = True
                    traps.append(self.paths[i][j].pos)
            if trapped:
                trapped_paths.append(self.paths[i])
                traps_in_paths.append(traps)
            self.PrintDisplay()
            self.ResetDisplay()
        print("Paths number:", len(self.paths))
        must_have_traps = []
        for i in range(len(traps_in_paths)):
            if traps_in_paths[i][-1] not in must_have_traps:
                must_have_traps.append(traps_in_paths[i][-1])
        for trap in must_have_traps:
            self.ChangeTile(trap, 'T')
        self.PrintDisplay()
        print("Must-have traps:", must_have_traps)

    def BFS(self, start_node):
        self.ResetVisited()
        self.ResetDisplay()
        bfs_queue = collections.deque()
        bfs_queue.append(start_node)
        while len(bfs_queue) > 0:
            node = bfs_queue.popleft()
            node_row = node.pos[0]
            node_col = node.pos[1]
            # self.ChangeTile(node.pos, '@')
            # self.PrintDisplay()
            # time.sleep(0.25)
            for n in node.adjacent_nodes:
                if not n.visited:
                    bfs_queue.append(n)
                    n.visited = True

    def DFS_Recursive(self, n, path):
        n.visited = True
        path.append(n)
        if self.maze[n.pos[0]][n.pos[1]] == 'F':
            print(path)
            self.paths.append(copy.deepcopy(path))
            print("FOUND PATH")
        else:
            for i in n.adjacent_nodes:
                if not i.visited:
                    self.DFS_Recursive(i, path)
        path.pop()
        n.visited = False

    def DFS_Simple(self, n, path=[]):
        path = path + [n]
        if self.maze[n.pos[0]][n.pos[1]] == 'F':
            self.paths.append(path)
        for i in n.adjacent_nodes:
            if i not in path:
                self.DFS_Simple(i, path)


    def GetNodeAtPos(self, position):
        for i in range(len(self.nodes)):
            if self.nodes[i].pos == position:
                return self.nodes[i]
        return None
    
    def MapOut(self, start_pos):
        self.ResetVisited()
        self.ResetDisplay()
        root = Node(0, start_pos)
        self.nodes.append(root)
        bfs_queue = collections.deque()
        bfs_queue.append(root)
        self.visited[start_pos[0]][start_pos[1]] = True
        queued_nodes = 0
        while len(bfs_queue) > 0:
            node = bfs_queue.popleft()
            node_row = node.pos[0]
            node_col = node.pos[1]
 
            up_pos = (node_row-1, node_col)
            down_pos = (node_row+1, node_col)
            left_pos = (node_row, node_col-1)
            right_pos = (node_row, node_col+1)
 
            up_passable = self.IsPassable((node_row-1, node_col))
            down_passable = self.IsPassable((node_row+1, node_col))
            left_passable = self.IsPassable((node_row, node_col-1))
            right_passable = self.IsPassable((node_row, node_col+1))

            if up_passable:
                up_node = self.GetNodeAtPos(up_pos)
                if up_node is None:
                    up_node = Node(node.data + 1, up_pos)
                    # up_node.parent = node
               # up_node = Node(node.data + 1, up_pos)
                node.adjacent_nodes.append(up_node)
            if down_passable:
                down_node = self.GetNodeAtPos(down_pos)
                if down_node is None:
                    down_node = Node(node.data + 1, down_pos)
                    # down_node.parent = node
               # down_node = Node(node.data + 1, down_pos)
                node.adjacent_nodes.append(down_node)
            if left_passable:
                left_node = self.GetNodeAtPos(left_pos)
                if left_node is None:
                    left_node = Node(node.data + 1, left_pos)
                    # left_node.parent = node
               # left_node = Node(node.data + 1, left_pos)
                node.adjacent_nodes.append(left_node)
            if right_passable:
                right_node = self.GetNodeAtPos(right_pos)
                if right_node is None:
                    right_node = Node(node.data + 1, right_pos)
                    # right_node.parent = node;
               # right_node = Node(node.data + 1, right_pos)
                node.adjacent_nodes.append(right_node)

            # if not up_passable and not down_passable and not left_passable and not right_passable or len(node.adjacent_nodes) < 1:
            #     print("NODE IS ISOLATED?")
            #     self.ChangeTile(node.pos, '*')
            #     self.PrintDisplay()
            #     time.sleep(5)

            for adj_node in node.adjacent_nodes:
                if not self.IsTileVisited(adj_node.pos):
                    queued_nodes += 1
                    bfs_queue.append(adj_node)
                    self.nodes.append(adj_node)
                    self.visited[adj_node.pos[0]][adj_node.pos[1]] = True

            # self.ChangeTile(node.pos, len(node.adjacent_nodes))
            # self.PrintDisplay()
            # time.sleep(0.01)

        self.ResetVisited()
        node_positions = [x.pos for x in self.nodes]
        node_adjacents = [x.adjacent_nodes for x in self.nodes]
        node_parents = [x.parent for x in self.nodes]

        passable_tile_count = 0
        impassable_node_count = 0
        same_nodes = 0
        adjacent_nodes = 0
        null_parent_nodes = 0

        for i in range(len(self.maze)):
            for j in range(len(self.maze[i])):
                if self.IsPassable((i, j)):
                    if (i,j) not in node_positions:
                        impassable_node_count += 1
                    passable_tile_count += 1

        # for i in range(len(self.nodes)):
        #     for j in range(len(self.nodes)):
        #         if self.nodes[i].pos == self.nodes[j].pos and self.nodes[i] != self.nodes[j]:
        #             print("FOUND SAME NODES!")
        #             same_nodes += 1

        for i in range(len(node_adjacents)):
            for j in range(len(node_adjacents[i])):
                if len(node_adjacents[i][j].adjacent_nodes) < 1:
                    adjacent_nodes += 1
                    # self.ChangeTile(node_adjacents[i][j].pos, '#')

        for i in range(len(node_parents)):
            if node_parents[i] is None:
                null_parent_nodes += 1

        self.PrintDisplay()

        unique_nodes = set(node_positions)
        print("Unique nodes:", len(unique_nodes), "Total nodes:", len(node_positions))
        print("Same nodes:", same_nodes)
        print("Adjacent nodes:", adjacent_nodes)
        print("Nodes not passable?:", impassable_node_count)
        print("Nodes queued:", queued_nodes)
        print("Nodes with null parent:", null_parent_nodes)

        print("Completed node-map of maze")
        print("Passable tiles:", passable_tile_count, "Nodes:", len(self.nodes))

def main():
    map_string = open(os.path.join(os.path.dirname(sys.argv[0]), "map3.txt"), "r").read()
    test = Trapper(map_string)
    test.PrintMaze()
    test.PrintDisplay()
    test.DoStuff()

start_time = time.time()

main()

end_time = time.time()
print("Time to run:", end_time - start_time, "seconds")