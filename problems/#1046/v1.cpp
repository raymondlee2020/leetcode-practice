class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        int x, y;
        while (q.size() > 1) {
            x = q.top();
            q.pop();
            y = q.top();
            q.pop();
            if (x == y) {
                continue;
            }
            q.push(x - y);
        }
        return q.empty() ? 0 : q.top();
    }
};