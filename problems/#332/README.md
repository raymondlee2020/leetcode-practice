# Problem 332 - Reconstruct Itinerary

## V1

Time Complexity: O(v + e)

Space Complexity: O(e)

- Traverse the graph likea tree by removing the edge after visiting.
- The implementation works due to there is at most one neighbor not in a cycle with self.
- The neighbor not in a cycle with self will be pushed into the reversed route due to the post-order traverse strategy.
