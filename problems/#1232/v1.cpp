class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) {
            return true;
        }
        bool ret = true;
        vector<int> p1 = coordinates[0], p2 = coordinates[1];
        if (p1[0] - p2[0] == 0) {
            for (auto coordinate: coordinates) {
                ret &= coordinate[0] == p1[0];
            }
            return ret;
        }
        double a = (p1[1] - p2[1]) * 1.0 / (p1[0] - p2[0]), b = p1[1] - a * p1[0];
        for (auto coordinate: coordinates) {
            ret &= coordinate[1] == a * coordinate[0] + b;
        }
        return ret;
    }
};