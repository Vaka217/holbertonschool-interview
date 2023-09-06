#!/usr/bin/python3
"""Calculates the fewest number of operations needed to result in exactly n H
characters in the file"""


def minOperations(n):
    """In a text file, there is a single character H. Your text editor can
    execute only two operations in this file: Copy All and Paste. Given a
    number n, write a method that calculates the fewest number of operations
    needed to result in exactly n H characters in the file.

    Arguments:
        n {int} -- The number of H characters in the file

    Return:
        int -- The fewest number of operations needed to result in n Hs,
        0 if its impossible
    """

    number_op = 2
    divisible = 2

    if n < 2:
        return 0
    while n > 1:
        if n % divisible != 0:
            divisible += 1
            number_op += 1
        else:
            n = n // divisible
            divisible = 2
            if n == 1:
                break
            number_op += 2
    return number_op
