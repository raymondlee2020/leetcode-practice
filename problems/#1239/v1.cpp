class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ret = 0, mask = 0;
        solve(ret, mask, arr, 0);
        return ret;
    }

    void solve(int& ret, int mask, vector<string>& arr, int idx) {
        int n = arr.size();
        if (idx == n) {
            int cnt = 0;
            while (mask) {
                if (mask & 1) {
                    ++cnt;
                }
                mask >>= 1;
            }
            ret = max(ret, cnt);
            return;
        }
        int pmask = mask;
        for (const auto& c: arr[idx]) {
            if (pmask & 1 << (c - 'a')) {
                pmask = 0;
                break;
            }
            pmask |= 1 << (c - 'a');
        }
        if (pmask) {
            solve(ret, pmask, arr, idx + 1);
        }
        solve(ret, mask, arr, idx + 1);
    }
};