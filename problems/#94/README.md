# Problem 94 - Binary Tree Inorder Traversal

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- Follow the inorder sequence (left -> self -> right) to traverse the tree.
- If the node is not null, leave self in the stack and start to traverse the left.
- Once the node is null, pop the parent out from the stack and push it into the ans, then start to traverse the right.
