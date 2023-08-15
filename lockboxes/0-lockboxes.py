#!/usr/bin/python3
"""Lockboxes Module 0"""


def canUnlock(box, boxes, unlocked):
    """Check keys in boxes"""
    for key in box:
        if key in unlocked or key > len(boxes) - 1:
            continue
        unlocked.append(key)
        canUnlock(boxes[key], boxes, unlocked)


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
