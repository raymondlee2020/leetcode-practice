class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long mid, l = 0, r = accumulate(batteries.begin(), batteries.end(), (long long) 0);
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (isPossible(n, batteries, mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l - 1;
    }

    bool isPossible(int n, vector<int>& batteries, long long time) {
        long long tt = time * n;
        for (long long battery: batteries) {
            tt -= min(battery, time);
        }
        return tt <= 0;
    }
};