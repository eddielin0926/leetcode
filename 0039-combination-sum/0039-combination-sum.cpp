class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> results;
        vector<int> path;
        dfs(candidates, target, 0, path, results);
        return results;
    }
private:
    void dfs(vector<int>& cands, int target, int start, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (target < 0) {
            return;
        }

        for (int i = start; i < cands.size(); i++) {
            path.push_back(cands[i]);
            dfs(cands, target - cands[i], i, path, res);
            path.pop_back();
        }

        return;
    }
};