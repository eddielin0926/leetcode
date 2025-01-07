class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        kvstore[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        if (kvstore.find(key) == kvstore.end()) {
            return "";
        }
        auto &values = kvstore[key];
        int n = values.size();
        int left = 0;
        int right = n - 1;
        string res = "";
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (values[middle].second <= timestamp) {
                res = values[middle].first; // current possible answer
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return res;
    }
private:
    unordered_map<string, vector<pair<string, int>>> kvstore;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */