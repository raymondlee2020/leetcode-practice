class Solution {
public:
    int countVowelPermutation(int n) {
        int MOD = 1e9 + 7;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, vector<char>> follows;
        unordered_map<char, int> prev, curr;
        follows['a'] = {'e'};
        follows['e'] = {'a', 'i'};
        follows['i'] = {'a', 'e', 'o', 'u'};
        follows['o'] = {'i', 'u'};
        follows['u'] = {'a'};
        for (const auto& v: vowels) {
            prev[v] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (const auto& v: vowels) {
                curr[v] = 0;
                for (const auto& f: follows[v]) {
                    curr[v] = (curr[v] + prev[f]) % MOD;
                }
            }
            swap(prev, curr);
        }
        int ret = 0;
        for (const auto& v: vowels) {
            ret = (ret + prev[v]) % MOD;
        }
        return ret;
    }
};