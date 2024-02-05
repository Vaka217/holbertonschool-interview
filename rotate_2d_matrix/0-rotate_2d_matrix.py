#!/usr/bin/python3
"""Rotate 2D Matrix Module"""


def rotate_2d_matrix(matrix):
    """Given a n X n 2D matrix, rotate it 90 degrees clockwise"""
    n = len(matrix)
    transpose = [[matrix[j][i] for j in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            matrix[i][j] = transpose[i][j]
    for row in matrix:
        row.reverse()
