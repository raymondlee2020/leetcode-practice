class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> baskets;
        int ret = 0, tmp;
        for (int l = 0, r = 0; r < fruits.size(); ++r) {
            if (baskets.size() >= 2 && baskets.find(fruits[r]) == baskets.end()) {
                while (baskets.size() >= 2) {
                    tmp = fruits[l++];
                    if (--baskets[tmp] == 0) {
                        baskets.erase(tmp);
                    }
                }
            }
            ++baskets[fruits[r]];
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};