"""Bubble Sort
"""
def bubbleSort(arr):
    """Bubble Sort (Iterative Implementation.)
    Time Complexity  : O(n^2)
    Space Complexity : O(1)

    Args : arr (list container)
    """

    for i in range(len(arr) - 1):
        swapped = False
        for pos in range(len(arr) - i - 1):
            if(arr[pos] > arr[pos + 1]):
                # swap the elements if in wrong order.
                (arr[pos], arr[pos + 1]) = (arr[pos + 1], arr[pos])
                swapped = True
        # break out of loop if no element is swapped in this iteration.
        if not swapped:
            break

    return arr


# print(bubbleSort([5,6,4,3,2,1,0,-1]))
# print(bubbleSort([j for j in range(10, -10, -1)]))
