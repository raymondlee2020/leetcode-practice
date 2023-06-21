class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long costbound = 0;
        int n = nums.size();
        vector<pair<int,int>> v;
        for (int i = 0; i < n; ++i) {
            v.push_back({nums[i],cost[i]});
            costbound += cost[i];
        }
        sort(v.begin(),v.end());
        costbound = (costbound + 1) / 2; 
        long long costacc = 0;
        int medidx;
        for (medidx = 0; medidx < n; ++medidx) {
            costacc += v[medidx].second;
            if (costacc >= costbound) {
                break;
            }
        }
        long long ret = 0;
        for (int i = 0; i < n; ++i) {
           ret += 1ll * abs(nums[i] - v[medidx].first) * cost[i];
        }
        return ret;  
    }
};