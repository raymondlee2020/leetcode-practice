# Problem 1611 - Minimum One Bit Operations to Make Integers Zero

## V1

Time Complexity: O(n)

Space Complexity: O(1)

- Define a_n as the count of operation to flip n-th bit
    - $a_n = 2 * a_{n - 1} + 1 = 2 * (2 * (... (2 * a_0 + 1) ...) + 1) + 1$.
    - $a_n = 2 ^ n + 2 ^ {n - 1} + 2 ^ {n - 2} + 2 ^ {n - 3} + ... + 1 = 2 ^ {n + 1} - 1$.
- To flip n-th bit, flip (n - 1)-th bit to 1 first.
    - The right nearest 1 bit can reduce the requiring operations.
    - For getting the min operations to make input zero, grouping each two 1 bits from left to right to maximize the operation reduction.
