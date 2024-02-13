class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ret = "";
        for (const auto& word: words) {
            if (isPalindrome(word)) {
                ret = word;
                break;
            }
        }
        return ret;
    }

    bool isPalindrome(const string& word) {
        int l = 0, r = word.size() - 1;
        while (r - l > 1) if (word[l++] != word[r--]) return false;
        return word[l] == word[r];
    }
};