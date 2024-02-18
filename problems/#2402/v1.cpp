class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> used_pq;
        priority_queue<int, vector<int>, greater<int>> unused_pq;
        pair<long, int> nxt_avail_room;
        vector<int> cnt(n, 0);
        sort(meetings.begin(), meetings.end());
        for (int i = 0; i < n; ++i) unused_pq.push(i);
        for (const auto& meeting: meetings) {
            while (used_pq.size() > 0 && used_pq.top().first <= meeting[0]) {
                unused_pq.push(used_pq.top().second);
                used_pq.pop();
            }
            if (unused_pq.size() > 0) {
                used_pq.push({meeting[1], unused_pq.top()});
                ++cnt[unused_pq.top()];
                unused_pq.pop();
            } else {
                nxt_avail_room = used_pq.top(), used_pq.pop();
                nxt_avail_room.first = meeting[1] + (nxt_avail_room.first - meeting[0]);
                used_pq.push(nxt_avail_room);
                ++cnt[nxt_avail_room.second];
            }
        }
        return distance(cnt.begin(), max_element(cnt.begin(), cnt.end()));
    }
};