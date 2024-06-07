class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for (auto& num : nums) {
            hashMap[num]++;
        }
        priority_queue<pair<int, int> > pq;
        for (auto &it: hashMap) {
            pq.push(make_pair(it.second, it.first));
        }
        vector<int> result;
        for (int i = 0; i < k; i++) {
            pair<int, int> top = pq.top();
            pq.pop();
            result.push_back(top.second);
        }
        return result;
    }
};