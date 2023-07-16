class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size(), m = people.size(), l, curr_skill, combo;
        unordered_map<int, vector<int>> dp;
        unordered_map<string, int> sm;
        dp.reserve(1 << n);
        dp[0] = {};
        for (int i = 0; i < n; ++i) {
            sm[req_skills[i]] = i;
        }
        for (int i = 0; i < m; ++i) {
            curr_skill = 0;
            l = people[i].size();
            for (int j = 0; j < l; ++j) {
                curr_skill |= 1 << sm[people[i][j]];
            }
            for (auto it = dp.begin(); it != dp.end(); ++it) {
                combo = curr_skill | it->first;
                if (dp.find(combo) == dp.end() || dp[combo].size() > it->second.size() + 1) {
                    dp[combo] = it->second;
                    dp[combo].push_back(i);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};