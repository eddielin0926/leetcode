class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<pair<int, int>> stck;
        for (int i = 0; i < n; ++i) {
            while (!stck.empty() && temperatures[i] > stck.top().first) {
                result[stck.top().second] = i - stck.top().second;
                stck.pop();
            }
            stck.push(make_pair(temperatures[i], i));
        }
        return result;
    }
};