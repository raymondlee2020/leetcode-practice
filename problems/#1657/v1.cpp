class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> cm1, cm2;
        map<int, int> im1, im2;
        for (const auto& c: word1) ++cm1[c];
        for (const auto& c: word2) ++cm2[c];
        map<char, int>::iterator it1, it2;
        for (it1 = cm1.begin(), it2 = cm2.begin(); it1 != cm1.end() && it2 != cm2.end(); ++it1, ++it2) {
            if (it1->first != it2->first) {
                return false;
            }
            ++im1[it1->second], ++im2[it2->second];
        }
        return im1 == im2;
    }
};