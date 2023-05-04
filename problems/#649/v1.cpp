class Solution {
public:
    string predictPartyVictory(string senate) {
        int i = 0;
        string ret;
        while (true) {
            if (senate[i] == 'R') {
                if (ban(senate, 'D', i) == -1) {
                    ret = "Radiant";
                    break;
                }
            } else if (senate[i] == 'D') {
                if (ban(senate, 'R', i) == -1) {
                    ret = "Dire";
                    break;
                }
            }
            i = ++i % senate.size();
        }
        return ret;
    }

    int ban(string& senate, char party, int s) {
        int curr = s + 1;
        while (curr != s) {
            if (senate[curr] == party) {
                senate[curr] = 'B';
                return curr;
            }
            curr = ++curr % senate.size();
        }
        return -1;
    }
};