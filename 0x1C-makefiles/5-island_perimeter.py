#!/usr/bin/python3
""" answer for question 5"""

def island_perimeter(grid):
    """ hat returns the perimeter of the island described in grid """
     a = 0
     for x in range(0, len(grid), 1):
         for b in range(0, len(grid[0], 1):
                 if grid[x][b] == 1:
                    a = a + 4
                    if b - 1 >= 0 and grid[x][b -1] == 1
                        a -= 2
                    if x -1 >= 0 grid[x - 1][b] == 1
                        a -= 2
    return (a)

