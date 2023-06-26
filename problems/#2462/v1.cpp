class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long ret = 0;
        if (n <= 2 * candidates) {
            sort(costs.begin(), costs.end());
            for (int i = 0; i < k; ++i) {
                ret += costs[i];
            }
            return ret;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int l = candidates - 1, r = n - candidates;
        for (int i = 0; i <= l; ++i) {
            pq.push({costs[i], i});
        }
        for (int i = n - 1; i >= r; --i) {
            pq.push({costs[i], i});
        }
        pair<int, int> hired;
        while ((r - l) > 1 && k-- > 0) {
            hired = pq.top();
            pq.pop();
            ret += hired.first;
            if (hired.second <= l) {
                ++l;
                pq.push({costs[l], l});
            } else {
                --r;
                pq.push({costs[r], r});
            }
        }
        for (; k > 0; --k) {
            hired = pq.top();
            pq.pop();
            ret += hired.first;
        }
        return ret;
    }
};