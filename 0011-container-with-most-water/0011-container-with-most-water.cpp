class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int currentMaxArea = 0;

        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            currentMaxArea = max(currentMaxArea, area);

            if (height[left] > height[right]) {
                right -= 1;
            }
            else {
                left += 1;
            }
        }

        return currentMaxArea;
    }
};