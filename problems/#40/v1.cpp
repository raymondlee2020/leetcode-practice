class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, ret, curr);
        return ret;
    }

    void backtrack(vector<int>& candidates, int target, int pv, vector<vector<int>>& ret, vector<int>& curr) {
        if (target == 0) {
            ret.push_back(curr);
            return;
        }
        for (int i = pv; i < candidates.size(); ++i) {
            if (candidates[i] > target) {
                break;
            }
            if (i > pv && candidates[i] == candidates[i - 1]) {
                continue;
            }
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, ret, curr);
            curr.pop_back();
        }
    }
};