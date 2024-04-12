class Solution:
    def trap(self, height: List[int]) -> int:
        ret, n, peakidx, prev, sub = 0, len(height), height.index(max(height)), 0, 0
        if height[peakidx] == 0:
            return 0
        while height[prev] == 0:
            prev += 1
        for i in range(prev + 1, peakidx + 1):
            if height[i] >= height[prev]:
                ret += (height[prev] * (i - prev - 1)) - sub
                prev, sub = i, 0
                continue
            sub += height[i]
        prev, sub = n - 1, 0
        while height[prev] == 0:
            prev -= 1
        for i in range(prev - 1, peakidx - 1, -1):
            if height[i] >= height[prev]:
                ret += (height[prev] * (prev - i - 1)) - sub
                prev, sub = i, 0
                continue
            sub += height[i]
        return ret