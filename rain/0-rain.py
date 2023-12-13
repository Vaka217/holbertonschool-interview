#!/usr/bin/python3
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

    if len(walls) < 3:
        return 0

    units, left_wall, left_idx = 0, 0, 0

    for idx, wall in enumerate(walls):
        if left_wall != 0 and wall != 0:
            units += (idx - left_idx - 1) * \
                (left_wall if left_wall <= wall else wall)
            left_wall, left_idx = wall, idx
        elif wall != 0:
            left_wall, left_idx = wall, idx

    return units
