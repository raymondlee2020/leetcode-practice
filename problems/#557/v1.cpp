class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), start = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        reverse(s, start, n - 1);
        return s;
    }

    void reverse(string& s, int start, int end) {
        for (; start < end; ++start, --end) {
            swap(s[start], s[end]);
        }
    }
};