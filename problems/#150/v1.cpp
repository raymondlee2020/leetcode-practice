class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int f, b;
        stack<int> s;
        for (const auto& token: tokens) {
            if (token == "+") {
                b = s.top(), s.pop();
                f = s.top(), s.pop();
                s.push(f + b);
            } else if (token == "-") {
                b = s.top(), s.pop();
                f = s.top(), s.pop();
                s.push(f - b);
            } else if (token == "*") {
                b = s.top(), s.pop();
                f = s.top(), s.pop();
                s.push(f * b);
            } else if (token == "/") {
                b = s.top(), s.pop();
                f = s.top(), s.pop();
                s.push(f / b);
            } else {
                s.push(atoi(token.c_str()));
            }
        }
        return s.top();
    }
};