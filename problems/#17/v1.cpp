class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.size() == 0) {
            return ret;
        }
        vector<string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int n = digits.size();
        queue<string> q;
        int s;
        string acc;
        q.push("");
        for (int i = 0; i < n; ++i) {
            s = q.size();
            for (int j = 0; j < s; ++j) {
                acc = q.front();
                q.pop();
                for (auto letter: m[digits[i] - '0']) {
                    acc.push_back(letter);
                    if (acc.size() == n) {
                        ret.push_back(acc);
                    } else {
                        q.push(acc);
                    }
                    acc.pop_back();
                }
            }
        }
        return ret;
    }
};