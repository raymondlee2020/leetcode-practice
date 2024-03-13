class Solution {
public:
    int pivotInteger(int n) {
        int l = 1, r = n, ls = 0, rs = 0;
        while (l < r) {
            if (ls < rs) {
                ls += l++;
            } else {
                rs += r--;
            }
        }
        return ls == rs ? l : -1;
    }
};