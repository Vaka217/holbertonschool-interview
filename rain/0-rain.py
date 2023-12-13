#!/usr/bin/env python3
"""Rain Module"""


def rain(walls):
    """Given a list of non-negative integers representing the heights of walls
    with unit width 1, as if viewing the cross-section of a relief map,
    calculate how many square units of water will be retained after it rains.

    walls is a list of non-negative integers.

    Return:
        Integer indicating total amount of rainwater retained.

    Assume that the ends of the list (before index 0 and after index walls[-1])
    are not walls, meaning they will not retain water.
    If the list is empty return 0."""

    if walls == []:
        return 0

    water, units, left_wall = 0, 0, 0

    for wall in walls:
        if left_wall != 0 and wall != 0:
            units += water * (left_wall if left_wall <= wall else wall)
            left_wall, water = wall, 0
        elif wall != 0:
            left_wall = wall
        elif left_wall != 0:
            water += 1

    return units
