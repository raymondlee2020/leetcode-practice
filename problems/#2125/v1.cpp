class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ret = 0, prev = 0, curr;
        for (const auto& row: bank) {
            curr = 0;
            for (const auto& cell: row) {
                curr += cell == '1' ? 1 : 0;
            }
            if (curr != 0) {
                ret += curr * prev;
                swap(prev, curr);
            }
        }
        return ret;
    }
};