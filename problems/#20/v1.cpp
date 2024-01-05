class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m = {
            {'{', '}'},
            {'[', ']'},
            {'(', ')'},
        };
        stack<char> cs;
        for (const auto& c: s) {
            if (c == '{' || c == '[' || c == '(') {
                cs.push(c);
            } else {
                if (cs.empty() || m[cs.top()] != c) {
                    return false;
                }
                cs.pop();
            }
        }
        return cs.empty();
    }
};