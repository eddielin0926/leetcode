class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<int> cars;
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; ++i) {
            pairs.push_back(make_pair(position[i], speed[i]));
        }
        sort(pairs.begin(), pairs.end(), greater<>());
        for (auto& p : pairs) {
            float t = (target - p.first) / (float)(p.second);
            if (!cars.empty()) {
                if (cars.top() < t) {
                    cars.push(t);
                }
            } else {
                cars.push(t);
            }
        }
        return cars.size();
    }
};