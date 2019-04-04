def insertionSort(a):
    """ Insertion sort (Iterative Implementation)
        Time Complexity  : O(n^2)
        Space Complexity : O(1)

        Args : a (list container)
    """
    if isinstance(a, list):
        for i in range(1, len(a)):
            key = a[i]
            pos = i - 1
            # Swap and Find the position for key to insert.
            while pos >= 0 and a[pos] > key:
                a[pos + 1] = a[pos]
                pos = pos - 1
            # Insert the key at its position.
            a[pos + 1] = key

    return a

def insertionSortR(a, len_):
    """ Insertion sort (Recursive Implementation)
        Time Complexity  : O(n^2)
        Space Complexity : O(n)

        Args : a (list container)
               len_ (length of list container)
    """
    if isinstance(a, list):

        if len_ <= 1:
            return

        insertionSortR(a, len_ - 1)

        key = a[len_ - 1]
        pos = len_ - 2
        while pos >= 0 and a[pos] > key:
            a[pos + 1] = a[pos]
            pos = pos - 1
        a[pos + 1] = key

    return a

def binaryInsertionSort():
    """
    """
    raise NotImplementedError
