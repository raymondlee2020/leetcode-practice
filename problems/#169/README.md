# Problem 169 - Majority Element

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- Use hashmap to count the numbers.

## V2

Time Complexity: O(n log n)

Space Complexity: O(log n)

- Divide and conquer.
- Keep finding the most frequent number in half size subslices.

## V3

Time Complexity: O(n)

Space Complexity: O(1)

- Boyer-Moore Voting Algorithm.
