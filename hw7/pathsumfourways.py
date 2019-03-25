# Authors: Taber McFarlin, Chris Byrne and Luke L
# We pledge our honor that we have abided by the Stevens Honor System

import sys
import heapq
import math
from vertex import vertex


def successors(grid: list, v: vertex, rows=0, cols=0):
     # Initialize optional args
    if rows == 0:
        rows = len(grid)
    if cols == 0:
        cols = len(grid[0])

    # Find all successors
    succ = []

    if (v.x > 0):
        succ.append(grid[v.y][v.x - 1])
    if (v.x < cols - 1):
        succ.append(grid[v.y][v.x + 1])

    if (v.y > 0):
        succ.append(grid[v.y - 1][v.x])
    if (v.y < rows - 1):
        succ.append(grid[v.y + 1][v.x])

    return succ


def decreaseKey(q: list, v: vertex):
    # index = q.index(vert)
    # while (index != 1 and vert < q[index / 2]):
    #   q[index] = q[index / 2]
    #   q[index / 2] = vert
    #   index = index / 2
    heapq.heapify(q)


def minSumPath(grid, rows=0, cols=0):
    # Initialize optional args
    if rows == 0:
        rows = len(grid)
    if cols == 0:
        cols = len(grid[0])

    # Initialize vertecies
    q = []
    vertGrid = []
    for i in range(rows):
        vertGrid.append([])
        for j in range(cols):
            newVert = vertex(j, i, int(grid[i][j]))
            vertGrid[i].append(newVert)

            if (i == 0 and j == 0):
                newVert.minSum = 0

            heapq.heappush(q, newVert)

    #
    for i in range(rows * cols):
        v: vertex = heapq.heappop(q)
        v.dequeued = True
        succ = successors(vertGrid, v, rows, cols)

        for s in succ:
            if not s.dequeued and v.minSum + v.value < s.minSum:
                s.minSum = v.minSum + v.value
                s.parent = v
                decreaseKey(q, s)

        # Backtrack path
        path = []
        if v.x == cols - 1 and v.y == rows -1:
            path.insert(0, v.value)
            while v.parent != None:
                v = v.parent
                path.insert(0, v.value)

            return path


def main():
    # Parse Input

     #if no args, usage
     if (len(sys.argv) < 2) :
        print("Usage: %s pathsumfourways.py inputmatrix" % sys.argv[0])
        sys.exit()

    #else keep going we have what we want
    filename = sys.argv[1]

    try:
        f = open(filename, 'r')

        contents = f.read().splitlines()

        rows = len(contents)
        for i in range(rows):
            contents[i] = contents[i].split(',')

        # Find minimal sum path
        path = minSumPath(contents, rows)

        # Output
        print("Min sum: " + str(sum(path)))
        print("Values:  " + str(path))
    except:
        print("Error: File '" + filename + "' not found.")


if (__name__ == "__main__"):
    main()
