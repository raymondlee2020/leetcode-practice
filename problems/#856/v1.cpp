class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size(), ret = 0, tmp;
        stack<int> ops;
        stack<pair<int, int>> cps;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ops.push(i);
            } else {
                tmp = 0;
                while (!cps.empty() && ops.top() < cps.top().first) tmp += cps.top().second, cps.pop();
                tmp = tmp == 0 ? 1 : tmp * 2;
                ops.pop();
                if (ops.empty()) {
                    ret += tmp;
                } else {
                    cps.push({i, tmp});
                }
            }
        }
        return ret;
    }
};