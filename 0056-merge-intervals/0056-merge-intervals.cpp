class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged{intervals[0]};

        for (int i = 1; i < intervals.size(); ++i) {
            auto& last = merged.back();
            if (last[1] >= intervals[i][0]) {
                last[1] = max(last[1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};