class Solution {
public:
    int rsize;

    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ret = 0, invalid = 0;
        vector<int> excess(n, 0);
        rsize = requests.size();
        solve(requests, excess, ret, 0, invalid, 0);
        return ret;
    }

    void solve(vector<vector<int>>& requests, vector<int>& excess, int& ret, int reqidx, int invalid, int achieved) {
        if (reqidx == rsize) {
            if (invalid > 0) {
                return;
            }
            ret = max(ret, achieved);
            return;
        }
        solve(requests, excess, ret, reqidx + 1, invalid, achieved);
        if (excess[requests[reqidx][0]] == 1) {
            --invalid;
        } else if (excess[requests[reqidx][0]] == 0) {
            ++invalid;
        }
        --excess[requests[reqidx][0]];
        if (excess[requests[reqidx][1]] == -1) {
            --invalid;
        } else if (excess[requests[reqidx][1]] == 0) {
            ++invalid;
        }
        ++excess[requests[reqidx][1]];
        solve(requests, excess, ret, reqidx + 1, invalid, achieved + 1);
        ++excess[requests[reqidx][0]], --excess[requests[reqidx][1]];
    }
};