# Problem 33 - Search in Rotated Sorted Array

## V1

Time Complexity: O(log n)

Space Complexity: O(log n)

- Leverage the code of #153 to get the unrotated, sorted array.
- Do the binary search.

## V2

Time Complexity: O(log n)

Space Complexity: O(log n)

- The half of the array must be an unrotated, sorted array, so we can ensure the target is in it or not.

## V3

Time Complexity: O(log n)

Space Complexity: O(1)

- Binary search.
- Find the deviation.

## V4

Time Complexity: O(log n)

Space Complexity: O(1)

- Binary search.
- Iterative.