# Problem 2742 - Painting the Walls

## V1

Time Complexity: O(n ^ 2)

Space Complexity: O(n)

- State: the ans of finish painting i walls.
- Base cases:
    - dp[0] = 0.
- State-transition equation:
    - dp[i] = min(dp[max(i - time[j] - 1, 0)] + cost[j] for j in range(n)).
- Knapsack problem.
