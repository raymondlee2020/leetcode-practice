class Solution {
public:
    vector<string> route;
    unordered_map<string, deque<string>> trips;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket: tickets) {
            trips[ticket[0]].push_back(ticket[1]);
        }
        for (auto& [src, dests]: trips) {
            sort(dests.begin(), dests.end());
        }
        visit("JFK");
        return vector<string>(route.crbegin(), route.crend());
    }

    void visit(string src) {
        auto& dests = trips[src];
        while (!dests.empty()) {
            string dest = dests.front();
            dests.pop_front();
            visit(dest);
        }
        route.push_back(src);
    }
};