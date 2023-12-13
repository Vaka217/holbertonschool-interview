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

    units, left_wall, left_idx, last_wall, last_idx = 0, 0, 0, 0, 0
    obstruction = 0

    for idx, wall in enumerate(walls):
        if len(walls) == idx + 1 and wall <= last_wall and \
                last_idx - left_idx > 1:
            units += (last_idx - left_idx - 1) * \
                (left_wall if left_wall <= last_wall else last_wall) - \
                obstruction + last_wall
            continue
        if wall > 0 and wall != last_wall:
            last_wall, last_idx = wall, idx
        if idx - left_idx > 1 and wall >= left_wall:
            units += (idx - left_idx - 1) * \
                (left_wall if left_wall <= wall else wall) - obstruction
            left_wall, left_idx, obstruction = wall, idx, 0
        elif wall >= left_wall:
            left_wall, left_idx = wall, idx
        elif idx > 0:
            obstruction += wall

    return units
