class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end()) + 1, mid;
        long cost;
        while (l < r) {
            mid = l + (r - l) / 2;
            cost = calculateCost(piles, mid);
            if (cost < h) {
                r = mid;
            } else if (cost > h) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

    long calculateCost(vector<int>& piles, int s) {
        long ret = 0;
        for (int pile: piles) {
            ret += ceil((double) pile / s);
        }
        return ret;
    }
};