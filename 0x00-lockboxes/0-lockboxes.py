#!/usr/bin/python3
"""Lockboxes file"""


def recursion(boxes, current_box, box_opened):
    """
    Using recursion to solve this problem
    """
    for key in current_box:
        if (key in box_opened):
            continue
        box_opened.append(key)
        return recursion(boxes, boxes[key], box_opened)
    return box_opened


def canUnlockAll(boxes):
    """
    Main function call recursion()
    """
    if not boxes:
        return False
    if len(boxes) == 1:
        if type(boxes[0]) != list:
            return False

    box_opened = []
    box_opened.append(0)

    for box in box_opened:
        for item in boxes[box]:
            if (item not in box_opened and
                    item != box and
                    item < len(boxes) and
                    item != 0):
                box_opened.append(item)

    if len(box_opened) == len(boxes):
        return True
    return False
