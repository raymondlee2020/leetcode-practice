class Solution {
public:
    struct Carry {
        int node;
        int path;
        int cost;
        Carry(int n, int p, int c) : node(n), path(p), cost(c) {}
    };

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int done = (1 << n) - 1;
        queue<Carry*> q;
        set<pair<int, int>> walked;
        int tpath;
        for (int i = 0; i < n; ++i) {
            tpath = (1 << i);
            q.push(new Carry(i, tpath, 0));
            walked.insert({i, tpath});
        }
        Carry* curr;
        Carry* tmp;
        int ret;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (curr->path == done) {
                ret = curr->cost;
                break;
            }
            for (auto neighbor: graph[curr->node]) {
                tpath = curr->path | (1 << neighbor);
                tmp = new Carry(neighbor, tpath, curr->cost + 1);
                if(walked.find({neighbor, tpath}) == walked.end()) {
                    walked.insert({neighbor, tpath});
                    q.push(tmp);
                }
            }
        }
        return ret;
    }
};