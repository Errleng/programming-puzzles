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
            self.visited[position[0]][position[1]] = True
            return is_visited

    def ResetVisited(self):
        for i in range(len(self.visited)):
            for j in range(len(self.visited[i])):
                self.visited[i][j] = False
    
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
    
    def MapOut(self, start_pos):
        self.ResetVisited()
        self.ResetDisplay()
        root = Node(0, start_pos)
        bfs_queue = collections.deque()
        bfs_queue.appendleft(root)
        self.visited[start_pos[0]][start_pos[1]] = True
        while len(bfs_queue) > 0:
            node = bfs_queue.pop()
            self.nodes.append(node)
            node_row = node.pos[0]
            node_col = node.pos[1]
            # self.visited[node_row][node_col] = True
 
            up_pos = (node_row-1, node_col)
            down_pos = (node_row+1, node_col)
            left_pos = (node_row, node_col-1)
            right_pos = (node_row, node_col+1)
 
            up_passable = self.IsPassable((node_row-1, node_col))
            down_passable = self.IsPassable((node_row+1, node_col))
            left_passable = self.IsPassable((node_row, node_col-1))
            right_passable = self.IsPassable((node_row, node_col+1))
            if up_passable:
               up_node = Node(node.data + 1, up_pos)
               node.adjacent_nodes.append(up_node)
            if down_passable:
               down_node = Node(node.data + 1, down_pos)
               node.adjacent_nodes.append(down_node)
            if left_passable:
               left_node = Node(node.data + 1, left_pos)
               node.adjacent_nodes.append(left_node)
            if right_passable:
               right_node = Node(node.data + 1, right_pos)
               node.adjacent_nodes.append(right_node)
            for adj_node in node.adjacent_nodes:
               if not self.IsTileVisited(adj_node.pos):
                   bfs_queue.appendleft(adj_node)
            self.ChangeTile(node.pos, len(node.adjacent_nodes))
            self.PrintDisplay()
            time.sleep(0.01)
        self.ResetVisited()
        node_positions = [x.pos for x in self.nodes]

        passable_tile_count = 0
        impassable_node_count = 0
        same_nodes = 0
        for i in range(len(self.maze)):
            for j in range(len(self.maze[i])):
                if self.IsPassable((i, j)):
                    if (i,j) not in node_positions:
                        impassable_node_count += 1
                    passable_tile_count += 1
        for i in range(len(self.nodes)):
            for j in range(len(self.nodes)):
                if self.nodes[i].pos == self.nodes[j].pos and self.nodes[i] != self.nodes[j]:
                    print("FOUND SAME NODES!")
                    same_nodes += 1
        print("Same nodes:", same_nodes)
        print("Nodes not passable?:", impassable_node_count)

        print("Completed node-map of maze")
        print("Passable tiles:", passable_tile_count, "Nodes:", len(self.nodes))

def main():
    map_string = open(os.path.join(os.path.dirname(sys.argv[0]), "map2.txt"), "r").read()
    test = Trapper(map_string)
    test.PrintMaze()
    test.PrintDisplay()
    test.DoStuff()

start_time = time.time()

main()

end_time = time.time()
print("Time to run:", end_time - start_time, "seconds")