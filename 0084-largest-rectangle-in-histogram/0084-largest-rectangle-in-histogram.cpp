class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        stack<pair<int, int>> stck; // index, height
        for (int i = 0; i < n; ++i) {
            int start = i;
            while (!stck.empty() && stck.top().second > heights[i]) {
                maxArea =
                    max(maxArea, stck.top().second * (i - stck.top().first));
                start = stck.top().first;
                stck.pop();
            }
            stck.push(make_pair(start, heights[i]));
        }
        while (!stck.empty()) {
            auto p = stck.top();
            maxArea = max(maxArea, p.second * (n - p.first));
            stck.pop();
        }
        return maxArea;
    }
};