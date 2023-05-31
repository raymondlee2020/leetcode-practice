class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> trip;
    unordered_map<string, pair<double, int>> record;

    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        trip[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string key = trip[id].first + "->" + stationName;
        if (record.find(key) == record.end()) {
            record[key] = {0.0, 0};
        }
        record[key].first = ((record[key].first * record[key].second) + (t - trip[id].second)) / (record[key].second + 1);
        ++record[key].second;
        trip.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return record[startStation + "->" + endStation].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */