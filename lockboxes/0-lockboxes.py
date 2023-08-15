#!/usr/bin/python3
"""Lockboxes Module 0"""


def canUnlockAll(boxes):
    """Can unlock all boxes?"""
    unlocked = [0]
    for box_idx, box in enumerate(boxes):
        if not box:
            continue
        for key in box:
            if key < len(boxes) and key not in unlocked and key != box_idx:
                unlocked.append(key)
    if len(unlocked) == len(boxes):
        return True
    return False
