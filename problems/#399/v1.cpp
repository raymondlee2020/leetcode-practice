class Solution {
public:
    map<string, double> records;
    map<string, vector<string>> graph;
    string conn = "->";
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        string a, b;
        double val;
        for (int i = 0; i < equations.size(); ++i) {
            a = equations[i][0];
            b = equations[i][1];
            val = values[i];
            records[a + conn + b] = val;
            records[b + conn + a] = 1 / val;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<double> ret;
        string start, end;
        for (int i = 0; i < queries.size(); ++i) {
            start = queries[i][0];
            end = queries[i][1];
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                ret.push_back(-1);
                continue;
            }
            if(start == end){
                ret.push_back(1);
                continue;
            }
            map<string, bool> visited;
            bool found = false;
            val = 1;
            dfs(start, end, visited, found, val);
            if (found) {
                ret.push_back(val);
            } else {
                ret.push_back(-1);
            }
        }
        return ret;
    }

    void dfs(string start, string end, map<string, bool>& visited, bool& found, double& val) {
        visited[start] = true;
        double tmp;
        for (const auto neighbor: graph[start]) {
            if (visited[neighbor]) {
                continue;
            }
            tmp = records[start + conn + neighbor];
            val *= tmp;
            if (neighbor == end) {
                found = true;
                return;
            }
            dfs(neighbor, end, visited, found, val);
            if (found) {
                return;
            }
            val /= tmp;
        }
    }
};