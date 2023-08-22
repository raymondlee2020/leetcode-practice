class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret = "";
        while (columnNumber > 0) {
            --columnNumber;
            ret.push_back((columnNumber % 26) + 65);
            columnNumber = columnNumber / 26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};