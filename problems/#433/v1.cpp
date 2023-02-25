class Solution {
public:
    map<string, vector<string>> graph;
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        for (const string gene: bank) {
            if (isNeighbor(startGene, gene)) {
                graph[startGene].push_back(gene);
            }
        }
        for (int i = 0; i < bank.size(); ++i) {
            for (int j = i + 1; j < bank.size(); ++j) {
                if (isNeighbor(bank[i], bank[j])) {
                    graph[bank[i]].push_back(bank[j]);
                    graph[bank[j]].push_back(bank[i]);
                }
            }
        }
        int ret = 0;
        queue<string> q;
        map<string, bool> visited;
        int size;
        string curr;
        q.push(startGene);
        while (!q.empty()) {
            size = q.size();
            for (int i = 0; i < size; ++i) {
                curr = q.front();
                q.pop();
                visited[curr] = true;
                if (curr == endGene) {
                    return ret;
                }
                for (const auto neighbor: graph[curr]) {
                    if (visited[neighbor]) {
                        continue;
                    }
                    q.push(neighbor);
                }
            }
            ++ret;
        }
        return -1;
    }

    bool isNeighbor(string a, string b) {
        int diff = 0;
        for (int i = 0; i < 8; ++i) {
            if (a[i] != b[i]) {
                ++diff;
            }
        }
        return diff == 1;
    }
};