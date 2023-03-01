class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxfreq = 0;
        map<char, int> m;
        for (const auto task: tasks) {
            ++m[task];
            maxfreq = max(maxfreq, m[task]);
        }
        // cooldown intervals: maxfreq - 1
        // unit in a interval: n + 1 (include process self)
        int ret = (maxfreq - 1) * (n + 1);
        // process the last one (the concept of plant tree problem)
        for (const auto e: m) {
            if (e.second == maxfreq) {
                ++ret;
            }
        }
        // consider cooldown period == 0
        return max((int) tasks.size(), ret);
    }      
};