#!/usr/bin/python3
"""
    this module contains a method to
    calculate how much water will be retained after it rains.
"""


def rain(walls):
    """calculate how much water will be retained after it rains."""
    if not walls or len(walls) == 0:
        return 0

    volume = 0
    left, right = 0, len(walls) - 1
    l_max, r_max = walls[left], walls[right]

    while left < right:
        l_max, r_max = max(walls[left], l_max), max(walls[right], r_max)
        if l_max <= r_max:
            volume += l_max - walls[left]
            left += 1
        else:
            volume += r_max - walls[right]
            right -= 1
    return volume
