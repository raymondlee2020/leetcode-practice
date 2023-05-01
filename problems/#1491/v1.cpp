class Solution {
public:
    double average(vector<int>& salary) {
        int maxs = INT_MIN, mins = INT_MAX, sums = 0, n = salary.size();
        for (const auto& s: salary) {
            maxs = max(maxs, s);
            mins = min(mins, s);
            sums += s;
        }
        sums -= maxs;
        sums -= mins;
        return sums / (double) (n - 2);
    }
};