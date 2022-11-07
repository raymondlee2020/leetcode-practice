# Problem 112 - Path Sum

## V1

Time Complexity: O(n)

Space Complexity: O(h)

- Recursively calculate the accumulative sum and compare with the target sum when traversing to the leaf.

## V2

Time Complexity: O(n)

Space Complexity: O(h)

- Minus the value of current node if it is not the leaf to exempt from the accumulative sum passing.
