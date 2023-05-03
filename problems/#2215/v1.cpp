class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> ns1(nums1.begin(), nums1.end()), ns2(nums2.begin(), nums2.end());
        vector<vector<int>> ret = {{}, {}};
        set<int>::iterator i = ns1.begin(), j = ns2.begin();
        while (i != ns1.end() && j != ns2.end()) {
            if (*i > *j) {
                ret[1].push_back(*j);
                ++j;
            } else if (*i < *j) {
                ret[0].push_back(*i);
                ++i;
            } else {
                ++i, ++j;
            }
        }
        while (i != ns1.end()) {
            ret[0].push_back(*i);
            ++i;
        }
        while (j != ns2.end()) {
            ret[1].push_back(*j);
            ++j;
        }
        return ret;
    }
};