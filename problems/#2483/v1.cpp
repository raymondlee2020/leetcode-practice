class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), ret = 0, minp = 0, currp = 0;
        for (char customer: customers) {
            if (customer == 'Y') {
                ++currp;
            }
        }
        minp = currp;
        for (int i = 0; i < n; ++i) {
            currp += customers[i] == 'Y' ? (-1) : 1;
            if (currp < minp) {
                ret = i + 1;
                minp = currp;
            }
        }
        return ret;
    }
};