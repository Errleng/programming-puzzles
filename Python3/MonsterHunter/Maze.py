import time
import os
import sys
import re

class Node(object):
    def __init__(self, data, position):
        self.data = data;
        self.position = position;
        self.adjacentNodes = []

class Trapper(object):
    def __init__(self, map):
        self.maze = [list(x) for x in re.split(r'\n', map)]
        self.display_maze = list(self.maze)
        self.size = len(self.maze)
        self.visited = [[True for x in range(self.size)] for y in range(self.size)]

    def PrintMaze(self):
        for row in range(len(self.maze)):
            for col in range(len(self.maze[row])):
                print(self.maze[row][col], end="")
            print()
    
    def PrintDisplay(self):
        for row in range(len(self.display_maze)):
            for col in range(len(self.display_maze[row])):
                print(self.display_maze[row][col], end="")
            print()
    
    def ChangeTile(self, tile_pos, symbol):
        this.display_maze[tile_pos[0]][tile_pos[1]] = symbol

def main():
    map_string = open(os.path.join(os.path.dirname(sys.argv[0]), "map1.txt"), "r").read()
    test = Trapper(map_string)
    test.PrintMaze()
    test.PrintDisplay()

start_time = time.time()

main()

end_time = time.time()
print("Time to run:", end_time - start_time, "seconds")