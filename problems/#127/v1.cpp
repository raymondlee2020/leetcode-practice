class Solution {
public:
    int n, k;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        n = beginWord.size();
        k = wordList.size();
        unordered_map<string, int> cost;
        unordered_map<string, vector<string>> graph;
        for (const auto word: wordList) {
            cost[word] = INT_MAX;
        }
        for (int i = 0; i < k - 1; ++i) {
            for (int j = i + 1; j < k; ++j) {
                if (isadj(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        queue<pair<string, int>> q;
        for (const auto word: wordList) {
            if (isadj(beginWord, word)) {
                q.push({word, 2});
            }
        }
        pair<string, int> curr;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (curr.second >= cost[curr.first]) {
                continue;
            }
            if (curr.first == endWord) {
                return curr.second;
            }
            cost[curr.first] = curr.second;
            for (const auto adj: graph[curr.first]) {
                cout << adj << endl;
                q.push({adj, curr.second + 1});
            }
        }
        return cost[endWord] == INT_MAX ? 0 : cost[endWord];
    }

    bool isadj(string a, string b) {
        int diff = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                ++diff;
            }
        }
        return diff == 1;
    }
};