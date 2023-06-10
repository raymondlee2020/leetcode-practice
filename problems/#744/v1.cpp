class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int mid, l = 0, r = letters.size();
        while (l < r) {
            mid = l + (r - l) / 2;
            if (letters[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l == letters.size() ? letters[0] : letters[l];
    }
};