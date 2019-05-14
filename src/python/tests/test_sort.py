"""Test sorting algorithms.
"""


import unittest
from sort.bubble_sort import bubbleSort

class Test_Sort(unittest.TestCase):


    def test_bubbleSort(self):
        """
        """
        l = [j for j in range(10, -11, -1)]
        self.assertEqual(bubbleSort(l), sorted(l))
