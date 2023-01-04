#!/usr/bin/python3
""" Validate inpot to get correct output """


def minOperations(n):
    """
    return minimum operations to get :n:
    """
    min_operation = 0
    base = 2

    if n <= 1:
        return 0
    while (base < (n + 1)):
        while (n % base == 0):
            min_operation += base
            n = n / base
        base += 1
    return min_operation
