class Solution {
public:
    int findMin(vector<int>& nums) {
        // Solution Binary search
        // 旋轉後的陣列會分為兩部分 eg. [3, 4, 5] [1, 2]
        // 小的部分一定會比在大的部分的任一元素大
        // 因此在搜尋時，我們可以由此判斷 pivot (middle) 在哪一部分
        // 再來移動搜尋範圍
        // nums[middle] >= nums[left] (等於考慮了邊界) => 找右邊
        // 反之，找左邊
        int n = nums.size();

        int minNum = nums[0];
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            if (nums[left] <= nums[right]) {
                minNum = min(minNum, nums[left]);
                break;
            }

            int middle = left + ((right - left) / 2);
            minNum = min(minNum, nums[middle]);
            if (nums[middle] >= nums[left]) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return minNum;
    }
};