# Problem 450 - Delete Node in a BST

## V1

Time Complexity: O(log n)

Space Complexity: O(1)

- Use binary search to find the key.
- Graft the key node's right subtree to the right of the left subtree's max node.
