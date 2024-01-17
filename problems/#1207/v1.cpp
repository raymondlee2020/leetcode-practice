class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int cnt, n = arr.size();
        vector<int> occurs;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n;) {
            cnt = 1;
            for (int j = i + 1; j < n; ++j) {
                if (arr[i] != arr[j]) {
                    break;
                }
                ++cnt;
            }
            occurs.push_back(cnt);
            i += cnt;
        }
        int m = occurs.size();
        sort(occurs.begin(), occurs.end());
        for (int i = 1; i < m; ++i) {
            if (occurs[i] == occurs[i - 1]) {
                return false;
            }
        }
        return true;   
    }
};