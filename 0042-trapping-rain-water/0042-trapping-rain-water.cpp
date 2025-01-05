class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 0) {
            return 0;
        }

        int left = 0;
        int right = n - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int water = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                left += 1;
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
            } else {
                right -= 1;
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
            }
        }

        return water;
    }
};