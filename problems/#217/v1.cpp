class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> existMap;
        for(unsigned int i = 0; i < nums.size(); i++)
        {
            int v = nums[i];
            if (existMap.find(v) != existMap.end()) {
                return true;
            }
            existMap[v] = true;
        }
        return false;
    }
};