class Solution {
public:
    int n;

    vector<vector<string>> partition(string s) {
        if (s.empty()) {
            return {};
        }
        vector<vector<string> > ret;
        vector<string> path;
        n = s.size();
        solve(ret, s, 0, path);
        return ret;
    }

    void solve(vector<vector<string>>& ret, string& s, int curr, vector<string>& path) {
        if (curr == n) {
            ret.push_back(path);
            return;
        }
        for (int i = curr; i < n; ++i) {
            if (isPalindrome(s, curr, i)) {
                path.push_back(s.substr(curr, i - curr + 1));
                solve(ret, s, i + 1, path);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};