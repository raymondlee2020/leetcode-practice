# Problem 15 - 3 Sum

## V1

Time Complexity: O(n^2)

Space Complexity: O(1)

- Decide two of the three numbers, then check the last number is in array or not, and vice versa.
- Sorted array can help us avoid the mistakes caused by duplication.
- Enumerate all possible pairs of numbers using two flags (pointers).