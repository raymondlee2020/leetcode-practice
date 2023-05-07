# Problem 1964 - Find the Longest Valid Obstacle Course at Each Position

## V1

Time Complexity: O(n log n)

Space Complexity: O(n)

- State: the longest increasing obstacle course end with the ith obstacle.
- Base cases:
    - dp = [] at the beginning.
- State-transition equation:
    - dp[len] = obstacles[i], given len as the longest increasing obstacle course length end with the ith obstacle.
- The function lower_bound use binary search to find the lowest index of the element >= the given value.
