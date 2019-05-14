"""Binary Search -- Divide and Conquer.
"""


def binarySearch(arr, key):
    """
    Binary Search -- Iterative Implementation.
    Time Complexity  : O(log n)
    Space Complexity : O(1)

    :param arr: sorted list Container
    :param key: value to be search for in list
    :return: index value if found [0, n-1], else False
    """
    (low, high) = (0, len(arr) - 1)
    while low <= high:
        mid = (low + high) / 2
        if arr[mid] == key:
            return mid
        elif arr[mid] > key:
            high = mid - 1
        else:
            low = mid + 1

    return False
