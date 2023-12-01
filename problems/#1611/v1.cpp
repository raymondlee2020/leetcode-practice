class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ret = 0, sign = isEvenOne(n), bit = 0, tmp;
        while (1 << bit <= n) {
            // check if the current bit is 1
            tmp = (1 << bit) & n;
            if (tmp) {
                // calculate the operation using the formula a_n = 2 ^ {n + 1} - 1
                ret += sign * ((1 << (bit + 1)) - 1);
                // for each grouping,
                // view the left one is the bit we want to make it zero
                // and the right one is the bit help us to fiish this task (reduce the operations),
                // so the sign keeping change when meeting 1 bit every time
                sign *= (-1);
            }
            ++bit;
        }
        return ret;
    }

    // perfect grouping if there are even 1 bits (start from sign = -1)
    // or we need to plus the operations to flip the last 1 bit (start from sign = 1)
    int isEvenOne(int n) {
        int ret = 0;
        while (n > 0) {
            n &= (n - 1);
            ++ret;
        }
        return ret % 2 == 0 ? -1 : 1;
    }
};