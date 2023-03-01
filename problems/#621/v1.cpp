class Solution {
public:
    struct cmp {
        bool operator()(const pair<char, int>* a, const pair<char, int>* b) {
            return a->second < b->second;
        }
    };

    int leastInterval(vector<char>& tasks, int n) {
        int cnt = tasks.size();
        if (n == 0) {
            return cnt;
        }
        map<char, pair<char, int>> m;
        for (const auto task: tasks) {
            if (m.find(task) == m.end()) {
                m[task] = make_pair(task, 0);
            }
            ++(m[task].second);
        }
        priority_queue<pair<char, int>*, vector<pair<char, int>*>, cmp> q;
        for (auto& [k, v]: m) {
            q.push(&v);
        }
        int ret = 0;
        queue<pair<char, int>*> cooldown;
        pair<char, int>* tmp;
        while (cnt > 0){
            tmp = NULL;
            if (!q.empty()) {
                tmp = q.top();
                q.pop();
                --(tmp->second);
                --cnt;
                if (tmp->second <= 0) {
                    tmp = NULL;
                }
            }
            cooldown.push(tmp);
            if (cooldown.size() > n) {
                tmp = cooldown.front();
                cooldown.pop();
                if (tmp != NULL) {
                    q.push(tmp);
                }
            }
            ++ret;
        }
        return ret;
    }
};