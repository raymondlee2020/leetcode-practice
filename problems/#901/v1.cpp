class StockSpanner {
public:
    int acc, last;
    // {max (last) price, span size}
    vector<pair<int, int>> spans;

    StockSpanner() {
        acc = last = 0;
    }
    
    int next(int price) {
        if (price < last) {
            spans.push_back({last, acc});
            acc = 1;
        } else {
            ++acc;
            pair<int, int> tmp;
            while (spans.size() > 0) {
                tmp = spans.back();
                if (tmp.first > price) {
                    break;
                }
                spans.pop_back();
                acc += tmp.second;
            }
        }
        last = price;
        return acc;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */