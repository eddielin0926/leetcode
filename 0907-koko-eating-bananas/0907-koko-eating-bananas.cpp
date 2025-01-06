class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // k 的最大值是 piles 中的最大值
        // Solution 1. Brute force
        // O(max(p)*p)
        // Solution 2. Binary search
        // k = 1 ... max(piles)
        // 用二分法搜尋可能最小的 k
        // O(log(max(p))*p)
        int n = piles.size();
        if (n == 0) {
            return 0;
        }

        int kMax = 1;
        for (int i = 0; i < n; i++) {
            kMax = max(kMax, piles[i]);
        }

        int left = 1;
        int right = kMax;
        int kMin = kMax;
        while (left <= right) {
            int k = left + ((right - left) / 2);
            long long hours = 0;
            for (int i = 0; i < n; i ++) {
                hours += piles[i] % k > 0 ? (piles[i] / k) + 1 : piles[i] / k;
            }
            if (hours <= h) {
                kMin = min(kMin, k);
                right = k - 1; // 找比較小的 k， hours 才會大於 h 
            } else {
                left = k + 1;
            }
        }
        return kMin;
    }
};