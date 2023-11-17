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
checked = [[0, 0]]
solutions = []

while n != N:
    for i in range(start, N):
        pedro = 0
        for check in checked:
            if abs(check[0] - n) != abs(check[1] - i) and check[0] != n and check[1] != i:
                pedro += 1
        if pedro == len(checked):
            checked.append([n, i])
            break
    if len(checked) != n + 1:
        if n == 0:
            for solution in solutions:
                print(solution)
            exit()
        n -= 1
        start = checked[-1][1] + 1
        checked.pop()
    else:
        start = 0
        n += 1
    if n == N:
        n = 0
        solutions.append([row[:] for row in checked])
        checked = [checked[0]]
        if checked[0][1] == N - 1:
            checked[0][0] += 1
            checked[0][1] = 0
        else:
            checked[0][1] += 1
        start = 0
