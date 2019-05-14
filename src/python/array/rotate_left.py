"""Rotate an array Left, by d.
refer : https://stackoverflow.com/questions/23321216/rotating-an-array-using-juggling-algorithm
"""


def rotate_left_1(arr, d):
    """Using Auxillary Space.
    Time Complexity  : O(n)
    Space Complexity : O(d)

    :param arr: a list Container
    :param d: units to rotate left
    """
    d = d % len(arr)
    temp = [arr[j] for j in range(d)]
    for val in range(d, len(arr)):
        arr[val - d] = arr[val]

    for val in range(d):
        arr[len(arr) - d + val] = temp[val]

    return arr


def rotate_left_2(arr, d):
    """One at a time.
    Time Complexity   : O(n*d)
    Space Complexity  : O(1)

    :param arr: a list Container
    :param d: units to rotate left
    """
    d = d % len(arr)
    def rotate_left_unit(arr):
        """Rotate left by 1.
        Time Complexity   : O(n)
        Space Complexity  : O(1)
        """
        return arr[1:] + [arr[0]]

    for j in range(d):
        arr = rotate_left_unit(arr)

    return arr


def rotate_left_3(arr, d):
    """Juggling Algorithm.
    Time Complexity   : O(n)
    Space Complexity  : O(1)

    :param arr: a list Container
    :param d: units to rotate left
    """
