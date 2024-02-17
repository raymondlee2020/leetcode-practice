class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int last = heights.size() - 1, diff, i;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (i = 0; i < last; ++i) {
            diff = heights[i + 1] - heights[i];
            if (diff <= 0) continue;
            pq.push(diff);
            if (pq.size() <= ladders) continue;
            if (bricks < pq.top()) break;
            bricks -= pq.top(), pq.pop();
        }
        return i;
    }
};