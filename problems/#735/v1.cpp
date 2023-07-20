class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size(), l = -1, r = 0;
        while (r < n) {
            while (r < n && asteroids[r] < 0) {
                asteroids[++l] = asteroids[r++];
            }
            while (r < n && asteroids[r] > 0) {
                asteroids[++l] = asteroids[r++];
            }
            while (l >= 0 && r < n && asteroids[l] > 0 && asteroids[r] < 0) {
                if (asteroids[l] + asteroids[r] == 0) {
                    ++r, --l;
                } else if (asteroids[l] + asteroids[r] > 0) {
                    ++r;
                } else {
                    --l;
                }
            }
        }
        return vector<int>(asteroids.begin(), asteroids.begin() + l + 1);
    }
};