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
n = 0
start = 0

chessboard = [[0] * N for _ in range(N)]
checked = [[0, 0]]

while n != N:
    juan = 0
    for i in range(start, N):
        pedro = 0
        for check in checked:
            if abs(check[0] - n) != abs(check[1] - i) and check[0] != n and check[1] != i:
                pedro += 1
        if pedro == len(checked):
            checked.append([n, i])
            break
    # if len(checked) != n + 1:
    #     print(n)
    #     n -= 1
    #     start = checked[-1][1]
    #     checked.pop()
    # else:
    n += 1

print(checked)
