class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> dists(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dists[i][j] = dist(words[i], words[j]);
                dists[j][i] = dist(words[j], words[i]);
            }
        }
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        vector<vector<int>> path(1 << n, vector<int>(n));
        int last = -1, min = INT_MAX, prev;
        for (int i = 1; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) > 0) {
                    prev = i - (1 << j);
                    if (prev == 0) {
                        dp[i][j] = words[j].size();
                    } else {
                        for (int k = 0; k < n; ++k) {
                            if (dp[prev][k] < INT_MAX && dp[prev][k] + dists[k][j] < dp[i][j]) {
                                dp[i][j] = dp[prev][k] + dists[k][j];
                                path[i][j] = k;
                            }
                        }
                    }
                }
                if (i == (1 << n) - 1 && dp[i][j] < min) {
                    min = dp[i][j];
                    last = j;
                }
            }
        }
        stack<int> s;
        int curr = (1 << n) - 1, tmp;
        while (curr > 0) {
            s.push(last);
            tmp = path[curr][last];
            curr -= (1 << last);
            last = tmp;
        }
        curr = s.top();
        s.pop();
        string ret = words[curr];
        prev = curr;
        while (!s.empty()) {
            curr = s.top();
            s.pop();
            ret.append(words[curr], words[curr].size() - dists[prev][curr]);
            prev = curr;
        }
        return ret;
    }

    int dist(string& a, string& b) {
        int s  = a.size();
        for (int i = 0; i < s; ++i) {
            if (b.starts_with(a.substr(i))) {
                return b.size() - a.size() + i;
            }
        }
        return b.size();
    }
};