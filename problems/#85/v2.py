class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        ret, n = 0, len(matrix[0])
        height = [0] * (n + 1)
        for row in matrix:
            for i in range(n):
                height[i] = height[i] + 1 if row[i] == '1' else 0
            stk = [-1]
            for i in range(n + 1):
                while height[i] < height[stk[-1]]:
                    h, w = height[stk.pop()], i - stk[-1] - 1
                    ret = max(ret, h * w)
                stk.append(i)
        return ret