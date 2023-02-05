class Solution {
public:
    int cnt;
    vector<bool> visited;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        cnt = rooms.size();
        if (cnt <= 1) {
            return true;
        }
        for (int i = 0; i < cnt; ++i) {
            visited.push_back(false);
        }
        bfs(rooms, 0);
        return cnt == 0;
    }

    void bfs(vector<vector<int>>& rooms, int idx) {
        if (visited[idx]) {
            return;
        }
        visited[idx] = true;
        --cnt;
        for (const auto key: rooms[idx]) {
            bfs(rooms, key);
        }
    }
};