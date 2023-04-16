class Solution {
public:
    int n;

    int minSpeedOnTime(vector<int>& dist, double hour) {
        n = dist.size();
        if (hour <= (double) (n - 1)) {
            return -1;
        }
        int min_speed = 0, max_speed = INT_MAX, mid_speed;
        double tmp_time;
        while (min_speed < max_speed) {
            mid_speed = min_speed + (max_speed - min_speed) / 2;
            tmp_time = calculateTime(dist, mid_speed);
            if (tmp_time < hour) {
                max_speed = mid_speed;
            } else if (tmp_time > hour) {
                min_speed = mid_speed + 1;
            } else {
                max_speed = mid_speed;
            }
        }
        return min_speed;
    }

    double calculateTime(vector<int>& dist, int speed) {
        double ret = 0;
        for (int i = 0; i < (n - 1); ++i) {
            ret += ceil((double) dist[i] / (double) speed);
        }
        ret += (double) dist[n - 1] / (double) speed;
        return ret;
    }
};