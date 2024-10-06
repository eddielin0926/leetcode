class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        int water = 0;

        int currentMaxHeight = 0;
        for (int i = 0; i < n; i++) {
            maxLeft[i] = currentMaxHeight;
            currentMaxHeight = max(currentMaxHeight, height[i]);
        }

        currentMaxHeight = 0;
        for (int i = n - 1; i >= 0; i--) {
            maxRight[i] = currentMaxHeight;
            currentMaxHeight = max(currentMaxHeight, height[i]);
        }

        for (int i = 0; i < n; i++) {
            water += max((min(maxLeft[i], maxRight[i]) - height[i]), 0);
        }

        return water;
    }
};