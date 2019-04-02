def insertion_sort(a):
    """ Insertion sort
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
