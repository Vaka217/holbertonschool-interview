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

    units, left_idx, last_idx = 0, 0, 0
    obstruction = 0

    for idx, wall in enumerate(walls):
        if len(walls) == idx + 1 and wall <= walls[last_idx] and \
                last_idx - left_idx > 1:
            units += (last_idx - left_idx - 1) * \
                (walls[left_idx] if walls[left_idx] <= walls[last_idx] else
                    walls[last_idx]) - obstruction + sum(walls[last_idx:-1])
            continue
        if wall > 0 and wall != walls[last_idx]:
            last_idx = idx
        if idx - left_idx > 1 and wall >= walls[left_idx]:
            units += (idx - left_idx - 1) * \
                (walls[left_idx] if walls[left_idx]
                 <= wall else wall) - obstruction
            walls[left_idx], left_idx, obstruction = wall, idx, 0
        elif wall >= walls[left_idx]:
            left_idx = idx
        elif idx > 0:
            obstruction += wall

    return units
