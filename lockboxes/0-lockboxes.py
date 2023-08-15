#!/usr/bin/python3
"""Lockboxes Module 0"""


def canUnlock(box, boxes, unlocked):
    """Check keys in boxes"""
    for keys in box:
        if keys in unlocked or keys > len(boxes) - 1:
            continue
        unlocked.append(keys)
        if keys > boxes.index(box):
            continue
        canUnlock(boxes[keys], boxes, unlocked)


def canUnlockAll(boxes):
    """Can unlock all boxes?"""
    unlocked = [0]
    if len(boxes) == 0:
        return True
    for i in range(len(boxes)):
        if i not in unlocked:
            continue
        canUnlock(boxes[i], boxes, unlocked)
    return False if len(unlocked) != len(boxes) else True
