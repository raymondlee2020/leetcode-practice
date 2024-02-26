class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> wsecret(n, -1), ret;
        vector<vector<pair<int, int>>> graph(n);
        queue<int> q;
        int curr;
        for (const auto& meeting: meetings) {
            graph[meeting[1]].push_back({meeting[0], meeting[2]});
            graph[meeting[0]].push_back({meeting[1], meeting[2]});
        }
        wsecret[0] = wsecret[firstPerson] = 0;
        q.push(0), q.push(firstPerson);
        while (!q.empty()) {
            curr = q.front(), q.pop();
            for (const pair<int, int> meeting: graph[curr]) {
                if (meeting.second >= wsecret[curr] && (wsecret[meeting.first] == -1 || meeting.second < wsecret[meeting.first])) {
                    wsecret[meeting.first] = meeting.second;
                    q.push(meeting.first);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (wsecret[i] != -1) ret.push_back(i);
        }
        return ret;
    }
};