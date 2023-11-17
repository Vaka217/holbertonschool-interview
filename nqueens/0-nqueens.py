#!/usr/bin/python3
"""N Queens Module"""

import sys

if len(sys.argv) != 2:
    print('Usage: nqueens N')
    exit(1)

if not str.isdigit(sys.argv[1]):
    print('N must be a number')
    exit(1)

if int(sys.argv[1]) < 4:
    print('N must be at least 4')
    exit(1)

N = int(sys.argv[1])
queens = [0] * N


def not_intersect(row, col):
    """Check if the [row, col] chessboard square intersect horizontally or
    diagonally with another already placed queen in previous rows

    Args:
        row: row of the chessboard square we are checking
        col: column of the chessboard square we are checking

    Returns:
        True if it doesn't intersect, False otherwise
    """
    for prev_row in range(row):
        prev_col = queens[prev_row]
        if prev_col == col or abs(prev_col - col) == abs(prev_row - row):
            return False
    return True


def nqueens(row):
    """Recursive function that's use for assigning queens to squares in the
    board. Through the loop and recursion it checks if by having at least a
    queen in each square has a combination with other queens to solve the
    problem."""
    if row == N:
        print([[idx, queen] for idx, queen in enumerate(queens)])

    for col in range(N):
        if not_intersect(row, col):
            queens[row] = col
            nqueens(row + 1)


if __name__ == "__main__":
    nqueens(0)
