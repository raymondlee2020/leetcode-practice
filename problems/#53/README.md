# Problem 53 - Maximum Subarray

## V1

Time Complexity: O(n)

Space Complexity: O(1)

- Greedy: keep finding larger sum.
- Dynamic Programming: for 1 <= i <= n, solve the same problem given subarray(1..i).
- Combine the two concepts, keep solving the same problem by deciding to accumulate with the previous sum or not.

## V2

Time Complexity: O(n)

Space Complexity: O(1)

- Simplify the code.
