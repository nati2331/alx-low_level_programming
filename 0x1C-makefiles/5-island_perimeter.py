#!/usr/bin/python3
"""
Technical interview preparation
"""

def island_perimeter(grid):
    """ Returns the perimeter of island described"""
    perimeter = 0

    num_rows = len(grid)

    if grid != []:
        num_columns = len(grid[0])

    for row in range(num_rows):
        for col in range(num_columns):
            if grid[row][col] == 1:
                if (row - 1) == -1 or grid[row - 1][col] == 0:
                    perimeter += 1
                if (row + 1) == num_rows or grid[row + 1][col] == 0:
                    perimeter += 1
                if (col - 1) == -1 or grid[row][col - 1] == 0:
                    perimeter += 1
                if (col + 1) == num_columns or grid[row][col + 1] == 0:
                    perimeter += 1

    return perimeter

