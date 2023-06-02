#!/usr/bin/python3
"""This module contains a method that rotate a 2d matrix 90 degrees"""


def rotate_2d_matrix(matrix):
    """Rotate a 2d matrix 90 degrees clockwise in-place"""
    matrix_len = len(matrix)

    for i in range(matrix_len):
        for j in range(i):
            matrix[i][j],  matrix[j][i] = matrix[j][i], matrix[i][j]

    for i in range(matrix_len):
        matrix[i].reverse()
