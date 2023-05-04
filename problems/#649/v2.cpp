class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size(), rt, dt;
        queue<int> rq, dq;
        for (int i = 0; i < n; ++i) {
            senate[i] == 'R' ? rq.push(i) : dq.push(i);
        }
        while (!rq.empty() && !dq.empty()) {
            rt = rq.front(), dt = dq.front();
            rq.pop(), dq.pop();
            rt < dt ? rq.push(rt + n) : dq.push(dt + n);
        }
        return rq.empty() ? "Dire" : "Radiant";
    }
};