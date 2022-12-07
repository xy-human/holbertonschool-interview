#!/usr/bin/python3


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
    box_opened = recursion(boxes, boxes[0], [])
    len_box_opened = len(box_opened) + 1
    if len(boxes) == len_box_opened:
        return True
    return False
